package com.example.livinglab;

import android.annotation.SuppressLint;
import android.app.AlarmManager;
import android.app.DatePickerDialog;
import android.app.PendingIntent;
import android.app.TimePickerDialog;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
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

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Date;
import java.util.List;
import java.util.Locale;
import java.util.Timer;
import java.util.TimerTask;

public class MainActivity extends AppCompatActivity {
    private static final String BROKER = "tcp://broker.emqx.io:1883";
    //private static final String BROKER = "tcp://54.253.168.98:1883";
    private static final String CLIENT_ID = "living-lab";
    private static final String TOPIC_PUB = "hub/control/app/8xff";
    private static final String TOPIC_SUB = "hub/status/app/8xff";
    static GridView gv;
    private Button addBtn, removeBtn, scanBtn;
    private ImageView timeBtn;
    private Switch otaBtn, vpnBtn;
    static ArrayList<Device> deviceList;
    int requestCode;
    private SharedPrefsManager prefsManager;
    private static MyArrayAdapter myAdapter;
    static MqttHandler mqttHandler;

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
        timeBtn = findViewById(R.id.alarm_img);
    }

    private void initMqttHandler() {
        mqttHandler = new MqttHandler();
        mqttHandler.connect(BROKER, CLIENT_ID);
        mqttHandler.subscribe(TOPIC_SUB);
        mqttHandler.setCallback(new MyMqttCallback());
    }

    private void setupDeviceList() {
        prefsManager = new SharedPrefsManager(this);
        requestCode = prefsManager.loadRequestCode();
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
        updateDeviceImageInView(view, device);
        sendDeviceStatus(device);
    }

    private void updateDeviceImageInView(View view, Device device) {
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
        @SuppressLint("InflateParams") View addDeviceView = LayoutInflater.from(this)
                .inflate(R.layout.layout_add_device, null);
        AlertDialog alertDialog = createDialog(addDeviceView);
        alertDialog.show();
        addDeviceView.findViewById(R.id.add_device_btn)
                .setOnClickListener(view -> addDevice(addDeviceView, alertDialog));
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
        AlertDialog alertDialog = createDialog(removeDeviceView);
        alertDialog.show();
        removeDeviceView.findViewById(R.id.remove_led_btn).setOnClickListener(view -> removeDevice(removeDeviceView, alertDialog));
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
    private void onTimeClick(View v) {
        View timeSettingView = LayoutInflater.from(this).inflate(R.layout.layout_set_time, null);
        AlertDialog alertDialog = createDialog(timeSettingView);

        Button confirmButton = timeSettingView.findViewById(R.id.confirm_button);
        confirmButton.setOnClickListener(view -> {
            confirmTime(timeSettingView, alertDialog);
        });

        alertDialog.show();
    }

    private void confirmTime(View timeSettingView, AlertDialog alertDialog) {
        EditText editTextHour = timeSettingView.findViewById(R.id.editTextHour);
        EditText editTextMinute = timeSettingView.findViewById(R.id.editTextMinute);
        EditText editTextDay = timeSettingView.findViewById(R.id.editTextDay);
        EditText editTextMonth = timeSettingView.findViewById(R.id.editTextMonth);
        EditText editTextDeviceName = timeSettingView.findViewById(R.id.editTextDeviceName);
        Spinner spinnerDeviceStatus = timeSettingView.findViewById(R.id.device_status);

        String hourText = editTextHour.getText().toString();
        String minuteText = editTextMinute.getText().toString();
        String dayText = editTextDay.getText().toString();
        String monthText = editTextMonth.getText().toString();
        String deviceName = editTextDeviceName.getText().toString();
        String deviceStatusStr = spinnerDeviceStatus.getSelectedItem().toString();
        boolean deviceStatus = deviceStatusStr.equals("On");

        if (!isValidTime(hourText, minuteText) || !isValidDate(dayText, monthText)) {
            Toast.makeText(this, "Invalid time or date", Toast.LENGTH_SHORT).show();
            return;
        }
        if (!isValidDeviceName(deviceName)){
            Toast.makeText(this, "Invalid device name", Toast.LENGTH_SHORT).show();
            return;
        }

        int hour = Integer.parseInt(hourText);
        int minute = Integer.parseInt(minuteText);
        int day = Integer.parseInt(dayText);
        int month = Integer.parseInt(monthText);

        Calendar calendar = Calendar.getInstance();
        calendar.set(Calendar.HOUR_OF_DAY, hour);
        calendar.set(Calendar.MINUTE, minute);
        calendar.set(Calendar.SECOND, 0);
        calendar.set(Calendar.DAY_OF_MONTH, day);
        calendar.set(Calendar.MONTH, month - 1);

        Calendar currentTime = Calendar.getInstance();
        if (calendar.before(currentTime)) {
            Toast.makeText(this, "Selected time is in the past", Toast.LENGTH_SHORT).show();
            return;
        }

        SimpleDateFormat dateFormat = new SimpleDateFormat("HH:mm dd/MM", Locale.getDefault());
        System.out.println(dateFormat.format(calendar.getTime()));
        System.out.println(deviceName);
        System.out.println(deviceStatus);

        handleTimeSelection(calendar, deviceName, deviceStatus);
        alertDialog.dismiss();
    }
    private boolean isValidDeviceName(String deviceName){
        for(Device device : deviceList){
            if(device.getName().equals(deviceName)){
                return true;
            }
        }
        return false;
    }
    private boolean isValidTime(String hourText, String minuteText) {
        try {
            int hour = Integer.parseInt(hourText);
            int minute = Integer.parseInt(minuteText);
            return (hour >= 0 && hour < 24) && (minute >= 0 && minute < 60);
        } catch (NumberFormatException e) {
            return false;
        }
    }

    private boolean isValidDate(String dayText, String monthText) {
        try {
            int day = Integer.parseInt(dayText);
            int month = Integer.parseInt(monthText);
            return (day > 0 && day <= 31) && (month > 0 && month <= 12);
        } catch (NumberFormatException e) {
            return false;
        }
    }
    private void handleTimeSelection(Calendar calendar, String deviceName, boolean deviceStatus) {
        requestCode++;
        Intent intent = new Intent(this, AlarmReceiver.class);
        intent.putExtra("deviceName", deviceName);
        intent.putExtra("deviceStatus", deviceStatus);
        PendingIntent pendingIntent = PendingIntent.getBroadcast(this, requestCode, intent, PendingIntent.FLAG_MUTABLE);

        AlarmManager alarmManager = (AlarmManager) getSystemService(Context.ALARM_SERVICE);

        if (alarmManager != null) {
            Log.d("Alarm Debug", "Setting alarm for " + deviceName + " at " + calendar.getTime() + " with requestCode " + requestCode);
            alarmManager.setExact(AlarmManager.RTC_WAKEUP, calendar.getTimeInMillis(), pendingIntent);
        }
    }

    private AlertDialog createDialog(View view) {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setView(view);
        return builder.create();
    }

    @Override
    protected void onPause() {
        super.onPause();
        prefsManager.saveDeviceList(deviceList);
        prefsManager.saveRequestCode(requestCode);
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

                addLeds(buffer.getLedList(), controller);
                addSws(buffer.getSwList(), controller);
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

    private void addLeds(List<Typedef.Led_t> leds, String controller) {
        for (Typedef.Led_t led : leds) {
            boolean isNewLed = true;
            for (Device device : deviceList) {
                if (device.getName().equals(led.getName())) {
                    isNewLed = false;
                    break;
                }
            }
            if (isNewLed) {
                boolean led_status = led.getStatus();
                int led_img = led_status ? R.drawable.led_on : R.drawable.led_off;
                runOnUiThread(() -> {
                    Device newLed = new Device(led_img, led.getName(), led.getMac(), led.getStatus(), controller, "Led");
                    deviceList.add(newLed);
                    myAdapter.notifyDataSetChanged();
                });
            }
        }
    }

    private void addSws(List<Typedef.Sw_t> sws, String controller) {
        for (Typedef.Sw_t sw : sws) {
            boolean isNewSw = true;
            for (Device device : deviceList) {
                if (device.getName().equals(sw.getName())) {
                    isNewSw = false;
                    break;
                }
            }
            if (isNewSw) {
                boolean sw_status = sw.getStatus();
                int sw_img = sw_status ? R.drawable.switch_on : R.drawable.switch_off;
                runOnUiThread(() -> {
                    Device newSw = new Device(sw_img, sw.getName(), sw.getMac(), sw.getStatus(), controller, "Switch");
                    deviceList.add(newSw);
                    newSw.setEp(sw.getEp());
                    myAdapter.notifyDataSetChanged();
                });
            }
        }
    }

    private void updateLeds(List<Typedef.Led_t> leds, int imgOn, int imgOff) {
        for (Typedef.Led_t led : leds) {
            for (int i = 0; i < deviceList.size(); i++) {
                Device device = deviceList.get(i);
                if (led.getMac() == device.getMac() && led.getName().equals(device.getName())) {
                    device.setStatus(led.getStatus());
                    device.setImg(device.isStatus() ? imgOn : imgOff);
                    updateDeviceImageInGridView(i, device.getImg());
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
                    updateDeviceImageInGridView(i, device.getImg());
                }
            }
        }
    }

    private void updateDeviceImageInGridView(int index, int imgRes) {
        runOnUiThread(() -> {
            View itemView = gv.getChildAt(index);
            if (itemView != null) {
                ImageView deviceImg = itemView.findViewById(R.id.device_img);
                deviceImg.setImageResource(imgRes);
            }
        });
    }
}
