package com.example.livinglab;

import android.annotation.SuppressLint;
import android.app.DatePickerDialog;
import android.app.TimePickerDialog;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.Switch;
import android.widget.TimePicker;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import com.google.protobuf.InvalidProtocolBufferException;

import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken;
import org.eclipse.paho.client.mqttv3.MqttCallback;
import org.eclipse.paho.client.mqttv3.MqttMessage;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Calendar;
import java.util.List;
import java.util.Locale;

public class MainActivity extends AppCompatActivity {
    private static final String BROKER = "tcp://broker.emqx.io:1883";
    private static final String CLIENT_ID = "living-lab";
    private static final String TOPIC_PUB = "hub/control/app/8xff";
    private static final String TOPIC_SUB = "hub/status/app/8xff";
    private GridView gv;
    private Button addBtn, removeBtn, scanBtn, timeBtn;
    private Switch otaBtn, vpnBtn;
    private static ArrayList<Device> deviceList;
    private SharedPrefsManager prefsManager;
    private static MyArrayAdapter myAdapter;
    private static MqttHandler mqttHandler;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);

        initViews();
        initMqttHandler();
        setupDeviceList();
        setupListeners();

        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
    }

    private void initViews() {
        gv = findViewById(R.id.device_list);
        addBtn = findViewById(R.id.add_btn);
        removeBtn = findViewById(R.id.remove_btn);
        vpnBtn = findViewById(R.id.vpn_btn);
        otaBtn = findViewById(R.id.ota_btn);
        scanBtn = findViewById(R.id.scan_btn);
        timeBtn = findViewById(R.id.time_btn);
    }

    private void initMqttHandler() {
        mqttHandler = new MqttHandler();
        mqttHandler.connect(BROKER, CLIENT_ID);
        mqttHandler.subscribe(TOPIC_SUB);
        mqttHandler.setCallback(new MyMqttCallback());
    }

    private void setupDeviceList() {
        prefsManager = new SharedPrefsManager(this);
        deviceList = prefsManager.loadDeviceList();
        myAdapter = new MyArrayAdapter(MainActivity.this, R.layout.layout_item_device, deviceList);
        gv.setAdapter(myAdapter);
    }

    private void setupListeners() {
        gv.setOnItemClickListener(this::onDeviceItemClick);
        addBtn.setOnClickListener(this::onAddDeviceClick);
        removeBtn.setOnClickListener(this::onRemoveDeviceClick);
        otaBtn.setOnClickListener(this::onOtaToggle);
        vpnBtn.setOnClickListener(this::onVpnToggle);
        scanBtn.setOnClickListener(this::onScanClick);
        timeBtn.setOnClickListener(this::onTimeClick);
    }

    private void onDeviceItemClick(AdapterView<?> parent, View view, int position, long id) {
        Device device = deviceList.get(position);
        device.setStatus(!device.isStatus());
        updateDeviceImage(view, device);
        sendDeviceStatus(device);
    }

    private void updateDeviceImage(View view, Device device) {
        ImageView deviceImg = view.findViewById(R.id.device_img);
        if (device.getDevice_type().equals("Led")) {
            device.setImg(device.isStatus() ? R.drawable.led_on : R.drawable.led_off);
        }
        else if (device.getDevice_type().equals("Switch")) {
            device.setImg(device.isStatus() ? R.drawable.switch_on : R.drawable.switch_off);
        }
        deviceImg.setImageResource(device.getImg());
    }

    private void sendDeviceStatus(Device device) {
        byte[] message = device.toBuffer().toByteArray();
        System.out.println(device.toBuffer());
        mqttHandler.publish(TOPIC_PUB, message);
    }

    private void onAddDeviceClick(View v) {
        @SuppressLint("InflateParams") View addDeviceView = LayoutInflater.from(this).inflate(R.layout.layout_add_device, null);
        AlertDialog alertDialog = createAddDeviceDialog(addDeviceView);
        alertDialog.show();
        addDeviceView.findViewById(R.id.add_device_btn).setOnClickListener(view -> addDevice(addDeviceView, alertDialog));
    }

    private AlertDialog createAddDeviceDialog(View addDeviceView) {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setView(addDeviceView);
        return builder.create();
    }

    private void addDevice(View addDeviceView, AlertDialog alertDialog) {
        EditText device_name = addDeviceView.findViewById(R.id.device_name);
        EditText device_mac = addDeviceView.findViewById(R.id.device_mac);
        Spinner spinner_controller = addDeviceView.findViewById(R.id.device_controller);
        Spinner spinner_device = addDeviceView.findViewById(R.id.device_type);

        String controller = spinner_controller.getSelectedItem().toString();
        String deviceType = spinner_device.getSelectedItem().toString();
        String name = device_name.getText().toString();
        String macStr = device_mac.getText().toString();

        if (isInputValid(name, macStr)) {
            long mac = Long.parseLong(macStr);
            if (isDeviceUnique(name, mac)) {
                addDeviceToList(name, mac, controller, deviceType);
                alertDialog.dismiss();
            } else {
                showToast("A device with the same name or mac already exists");
            }
        } else {
            showToast("Please enter both a valid name and mac");
        }
    }

    private boolean isInputValid(String name, String macStr) {
        try {
            Long.parseLong(macStr);
            return !name.isEmpty() && !macStr.isEmpty();
        } catch (NumberFormatException e) {
            return false;
        }
    }

    private boolean isDeviceUnique(String name, long mac) {
        for (Device device : deviceList) {
            if (device.getName().equals(name) || device.getMac() == mac) {
                return false;
            }
        }
        return true;
    }

    private void addDeviceToList(String name, long mac, String controller, String deviceType) {
        int imgRes = deviceType.equals("Led") ? R.drawable.led_off : R.drawable.switch_off;
        deviceList.add(new Device(imgRes, name, mac, false, controller, deviceType));
        myAdapter.notifyDataSetChanged();
    }

    private void onRemoveDeviceClick(View v) {
        View removeDeviceView = LayoutInflater.from(this).inflate(R.layout.layout_remove_device, null);
        AlertDialog alertDialog = createRemoveDeviceDialog(removeDeviceView);
        alertDialog.show();
        removeDeviceView.findViewById(R.id.remove_led_btn).setOnClickListener(view -> removeDevice(removeDeviceView, alertDialog));
    }

    private AlertDialog createRemoveDeviceDialog(View removeDeviceView) {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setView(removeDeviceView);
        return builder.create();
    }

    private void removeDevice(View removeDeviceView, AlertDialog alertDialog) {
        String name = ((EditText) removeDeviceView.findViewById(R.id.led_name_remove)).getText().toString();
        if (!name.isEmpty()) {
            if (removeDeviceFromList(name)) {
                alertDialog.dismiss();
            } else {
                showToast("Device not found");
            }
        } else {
            showToast("Please enter Device name");
        }
    }

    private boolean removeDeviceFromList(String name) {
        for (int i = 0; i < deviceList.size(); i++) {
            if (deviceList.get(i).getName().equals(name)) {
                deviceList.remove(i);
                myAdapter.notifyDataSetChanged();
                return true;
            }
        }
        return false;
    }

    private void onOtaToggle(View v) {
        boolean checkOta = otaBtn.isChecked();
        Typedef.Ota_t.Builder otaBuilder = Typedef.Ota_t.newBuilder().setCheckOta(checkOta);
        Typedef.Buffer ota = Typedef.Buffer.newBuilder()
                .setMacHub("8xff")
                .setSender(Typedef.User_t.valueOf("App"))
                .setReceiver(Typedef.User_t.valueOf("Server"))
                .setCotroller(Typedef.User_t.valueOf("Ota"))
                .setOta(otaBuilder)
                .build();
        byte[] message = ota.toByteArray();
        System.out.println(ota);
        mqttHandler.publish(TOPIC_PUB, message);
    }

    private void onVpnToggle(View v) {
        boolean status = vpnBtn.isChecked();
        Typedef.Vpn_t.Builder vpnBuilder = Typedef.Vpn_t.newBuilder().setStatus(status);
        Typedef.Buffer vpn = Typedef.Buffer.newBuilder()
                .setMacHub("8xff")
                .setSender(Typedef.User_t.valueOf("App"))
                .setReceiver(Typedef.User_t.valueOf("Server"))
                .setVpn(vpnBuilder)
                .build();
        byte[] message = vpn.toByteArray();
        System.out.println(vpn);
        mqttHandler.publish(TOPIC_PUB, message);
    }

    private void onScanClick(View v) {
        Typedef.Buffer scan = Typedef.Buffer.newBuilder()
                .setMacHub("8xff")
                .setSender(Typedef.User_t.valueOf("App"))
                .setReceiver(Typedef.User_t.valueOf("Server"))
                .setCotroller(Typedef.User_t.valueOf("Zigbee"))
                .build();
        byte[] message = scan.toByteArray();
        System.out.println(scan);
        mqttHandler.publish(TOPIC_PUB, message);
    }

    private void showToast(String message) {
        Toast.makeText(MainActivity.this, message, Toast.LENGTH_SHORT).show();
    }

    private void onTimeClick(View v){
        
    }

    @Override
    protected void onPause() {
        super.onPause();
        prefsManager.saveDeviceList(deviceList);
    }

    class MyMqttCallback implements MqttCallback {
        @Override
        public void connectionLost(Throwable cause) {}

        @SuppressLint("SetTextI18n")
        @Override
        public void messageArrived(String topic, MqttMessage message) throws Exception {
            if (topic.equals("hub/status/app/8xff")) {
                Typedef.Buffer buffer = Typedef.Buffer.parseFrom(message.getPayload());
                String controller = buffer.getCotroller().toString();
                System.out.println(buffer);

                updateLeds(buffer.getLedList(), R.drawable.led_on, R.drawable.led_off);
                updateSws(buffer.getSwList(), R.drawable.switch_on, R.drawable.switch_off);

                if ("Hub".equals(controller)){
                    sendDeviceListToServer();
                }

            }
        }

        @Override
        public void deliveryComplete(IMqttDeliveryToken token) {}
    }

    private void sendDeviceListToServer(){
        Typedef.Buffer.Builder bufferBuilder = Typedef.Buffer.newBuilder()
                .setMacHub("8xff")
                .setSender(Typedef.User_t.valueOf("App"))
                .setReceiver(Typedef.User_t.valueOf("Server"))
                .setCotroller(Typedef.User_t.valueOf("Hub"));

        for (Device device : deviceList) {
            if (device.getDevice_type().equals("Led")) {
                Typedef.Led_t.Builder ledBuilder = Typedef.Led_t.newBuilder()
                        .setName(device.getName())
                        .setMac(device.getMac())
                        .setStatus(device.isStatus());
                bufferBuilder.addLed(ledBuilder);
            }
            else if (device.getDevice_type().equals("Switch")){
                Typedef.Sw_t.Builder swBuilder = Typedef.Sw_t.newBuilder()
                        .setName(device.getName())
                        .setMac(device.getMac())
                        .setStatus(device.isStatus());
                bufferBuilder.addSw(swBuilder);
            }
        }

        Typedef.Buffer buffer = bufferBuilder.build();
        byte[] mess = buffer.toByteArray();
        mqttHandler.publish(TOPIC_PUB, mess);
    }

    private void updateLeds(List<Typedef.Led_t> leds, int imgOn, int imgOff) {
        for (Typedef.Led_t led : leds) {
            for (int i = 0; i < deviceList.size(); i++) {
                Device device = deviceList.get(i);
                if (led.getMac() == device.getMac() && led.getName().equals(device.getName())) {
                    device.setStatus(led.getStatus());
                    device.setImg(device.isStatus() ? imgOn : imgOff);
                    updateDeviceImage(i, device.getImg());
                }
            }
        }
    }
    private void updateSws(List<Typedef.Sw_t> sws, int imgOn, int imgOff) {
        for (Typedef.Sw_t sw : sws) {
            for (int i = 0; i < deviceList.size(); i++) {
                Device device = deviceList.get(i);
                if (sw.getMac() == device.getMac() && sw.getEp() == device.getEp()) {
                    device.setStatus(sw.getStatus());
                    device.setImg(device.isStatus() ? imgOn : imgOff);
                    updateDeviceImage(i, device.getImg());
                }
            }
        }
    }

    private void updateDeviceImage(int index, int imgRes) {
        runOnUiThread(() -> {
            View itemView = gv.getChildAt(index);
            if (itemView != null) {
                ImageView deviceImg = itemView.findViewById(R.id.device_img);
                deviceImg.setImageResource(imgRes);
            }
        });
    }
}
