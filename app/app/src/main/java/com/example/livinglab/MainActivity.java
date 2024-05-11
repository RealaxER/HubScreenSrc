package com.example.livinglab;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken;
import org.eclipse.paho.client.mqttv3.MqttCallback;
import org.eclipse.paho.client.mqttv3.MqttMessage;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    private static final String BROKER = "tcp://broker.emqx.io:1883";
    //private static final String BROKER = "tcp://54.253.168.98:1883";
    private static final String CLIENT_ID = "living-lab-app";
    private static final String TOPIC_DEVICE = "hub/control/app/8xff";
    int[] img = {R.drawable.switch_off, R.drawable.led_off, R.drawable.switch_off, R.drawable.led_off, R.drawable.led_off, R.drawable.switch_off};
    String[] name = {"Sw 1", "Led 1", "Sw 2", "Led 2", "Led 3", "Sw 3"};
    long[] mac = {1, 2, 3, 4, 5, 6};
    String[] controller = {"Zigbee", "Wifi", "Wifi", "Zigbee", "Wifi", "Ble"};
    String[] device_type = {"Switch", "Led", "Switch", "Led", "Led", "Switch"};
    //int[] img = {};
    //String[] name = {};
    //String[] mac = {};
    //static TextView mac_text;
    GridView gv;
    Button add_btn, remove_btn;
    @SuppressLint("UseSwitchCompatOrMaterialCode")
    Switch ota_btn, vpn_btn;
    Button scan_btn;
    static ArrayList<Device> myList;
    MyArrayAdapter myAdapter;
    private static MqttHandler mqttHandler;
    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);

        mqttHandler = new MqttHandler();
        mqttHandler.connect(BROKER,CLIENT_ID);

        mqttHandler.subscribe("hub/status/app/8xff");
        mqttHandler.setCallback(new MyMqttCallback());

        gv = findViewById(R.id.device_list);
        //mac_text = findViewById(R.id.mac_text);
        add_btn = findViewById(R.id.add_btn);
        remove_btn = findViewById(R.id.remove_btn);
        vpn_btn = findViewById(R.id.vpn_btn);
        ota_btn = findViewById(R.id.ota_btn);
        scan_btn = findViewById(R.id.scan_btn);

        myList = new ArrayList<>();
        for(int i = 0; i < name.length; i++){
            myList.add(new Device(img[i], name[i], mac[i], false, controller[i], device_type[i]));
        }
        myAdapter = new MyArrayAdapter(MainActivity.this, R.layout.layout_item_device, myList);
        gv.setAdapter(myAdapter);

        gv.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                byte[] message;
                Device device = myList.get(position);
                device.setStatus(!device.isStatus());
                ImageView device_img = view.findViewById(R.id.device_img);
                Typedef.Buffer.Builder bufferBuilder = Typedef.Buffer.newBuilder()
                        .setMacHub("8xff")
                        .setSender(Typedef.User_t.valueOf("App"))
                        .setReceiver(Typedef.User_t.valueOf("Server"))
                        .setCotroller(Typedef.User_t.valueOf(device.getController()));

                if (device.getDevice_type().equals("Led")) {
                    device.setImg(device.isStatus() ? R.drawable.led_on : R.drawable.led_off);
                    device_img.setImageResource(device.getImg());
                    Typedef.Led_t.Builder led_t = Typedef.Led_t.newBuilder()
                            .setName(device.getName())
                            .setMac(device.getMac())
                            .setStatus(device.isStatus());
                    bufferBuilder.addLed(led_t);
                } else if (device.getDevice_type().equals("Switch")) {
                    device.setImg(device.isStatus() ? R.drawable.switch_on : R.drawable.switch_off);
                    device_img.setImageResource(device.getImg());
                    Typedef.Sw_t.Builder sw_t = Typedef.Sw_t.newBuilder()
                            .setName(device.getName())
                            .setMac(device.getMac())
                            .setStatus(device.isStatus());
                    bufferBuilder.addSw(sw_t);
                }

                Typedef.Buffer buffer = bufferBuilder.build();
                System.out.println(buffer.toString());
                message = buffer.toByteArray();
                mqttHandler.publish(TOPIC_DEVICE, message);
            }
        });


        add_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                View addDeviceView = LayoutInflater.from(MainActivity.this).inflate(R.layout.layout_add_device, null);

                AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);
                builder.setView(addDeviceView);

                AlertDialog alertDialog = builder.create();
                alertDialog.show();

                Button add_device_btn = addDeviceView.findViewById(R.id.add_device_btn);

                add_device_btn.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        EditText device_name = addDeviceView.findViewById(R.id.device_name);
                        EditText device_mac = addDeviceView.findViewById(R.id.device_mac);
                        Spinner spinner_controller = addDeviceView.findViewById(R.id.device_controller);
                        Spinner spinner_device = addDeviceView.findViewById(R.id.device_type);

                        String controller = spinner_controller.getSelectedItem().toString();
                        String device_type = spinner_device.getSelectedItem().toString();
                        String name = device_name.getText().toString();
                        String mac_str = device_mac.getText().toString();
                        long mac = 0;
                        boolean mac_is_valid = true;
                        try{
                            mac = Long.parseLong(mac_str);
                        } catch (NumberFormatException e) {
                            mac_is_valid = false;
                            Toast.makeText(MainActivity.this, "Invalid mac", Toast.LENGTH_SHORT).show();
                        }

                        boolean led_check = false;
                        for (Device device : myList) {
                            if (device.getName().equals(name) || (device.getMac() == mac)) {
                                led_check = true;
                                break;
                            }
                        }

                        if (!led_check) {
                            if (!name.isEmpty() && !mac_str.isEmpty() && mac_is_valid) {
                                if (device_type.equals("Led")) {
                                    myList.add(new Device(R.drawable.led_off, name, mac, false, controller, device_type));
                                } else myList.add(new Device(R.drawable.switch_off, name, mac, false, controller, device_type));
                                myAdapter.notifyDataSetChanged();
                                alertDialog.dismiss();
                            } else if (mac_is_valid){
                                Toast.makeText(MainActivity.this, "Please enter both name and mac", Toast.LENGTH_SHORT).show();
                            }
                        } else {
                            Toast.makeText(MainActivity.this, "Device with the same name or mac already exists", Toast.LENGTH_SHORT).show();
                        }
                    }
                });
            }
        });

        remove_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                View removeLedView = LayoutInflater.from(MainActivity.this).inflate(R.layout.layout_remove_device, null);

                AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);
                builder.setView(removeLedView);

                AlertDialog alertDialog = builder.create();
                alertDialog.show();

                Button remove_led_btn = removeLedView.findViewById(R.id.remove_led_btn);
                remove_led_btn.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View v) {
                        EditText led_name = removeLedView.findViewById(R.id.led_name_remove);
                        String name = led_name.getText().toString();
                        if (!name.isEmpty()) {
                            for (int i = 0; i < myList.size(); i++) {
                                Device device = myList.get(i);
                                if (device.getName().equals(name)) {
                                    myList.remove(i);
                                    myAdapter.notifyDataSetChanged();
                                    alertDialog.dismiss();
                                    return;
                                }
                            }
                            Toast.makeText(MainActivity.this, "Led not found", Toast.LENGTH_SHORT).show();
                        } else{
                            Toast.makeText(MainActivity.this, "Please enter Device name", Toast.LENGTH_SHORT).show();
                        }
                    }
                });
            }
        });

        ota_btn.setOnClickListener(new View.OnClickListener() {
            @SuppressLint("SetTextI18n")
            @Override
            public void onClick(View v) {
                ota_btn.setOnClickListener(new View.OnClickListener() {
                    @SuppressLint("SetTextI18n")
                    @Override
                    public void onClick(View v) {
                        boolean checkOta = ota_btn.isChecked();
                        Typedef.Ota_t.Builder ota_t = Typedef.Ota_t.newBuilder().setCheckOta(checkOta);
                        Typedef.Buffer ota = Typedef.Buffer.newBuilder()
                                .setMacHub("8xff")
                                .setSender(Typedef.User_t.valueOf("App"))
                                .setReceiver(Typedef.User_t.valueOf("Server"))
                                .setCotroller(Typedef.User_t.valueOf("Ota"))
                                .setOta(ota_t)
                                .build();
                        byte[] message = ota.toByteArray();
                        mqttHandler.publish("hub/control/app/8xff", message);
                    }
                });
            }
        });

        vpn_btn.setOnClickListener(new View.OnClickListener() {
            @SuppressLint("SetTextI18n")
            @Override
            public void onClick(View v) {
                boolean status = vpn_btn.isChecked();
                Typedef.Vpn_t.Builder vpn = Typedef.Vpn_t.newBuilder().setStatus(status);
                Typedef.Buffer buffer = Typedef.Buffer.newBuilder()
                        .setMacHub("8xff")
                        .setSender(Typedef.User_t.valueOf("App"))
                        .setReceiver(Typedef.User_t.valueOf("Server"))
                        .setVpn(vpn)
                        .build();
                byte[] message = buffer.toByteArray();
                mqttHandler.publish("hub/control/app/8xff", message);
            }
        });

        scan_btn.setOnClickListener(new View.OnClickListener() {
            @SuppressLint("SetTextI18n")
            @Override
            public void onClick(View v) {
                Typedef.Buffer buffer = Typedef.Buffer.newBuilder()
                        .setMacHub("8xff")
                        .setSender(Typedef.User_t.valueOf("App"))
                        .setReceiver(Typedef.User_t.valueOf("Server"))
                        .setCotroller(Typedef.User_t.valueOf("Zigbee"))
                        .build();
                byte[] message = buffer.toByteArray();
                mqttHandler.publish("hub/control/app/8xff", message);
            }
        });

        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
    }
    static class MyMqttCallback implements MqttCallback {

        @Override
        public void connectionLost(Throwable cause) {

        }

        @SuppressLint("SetTextI18n")
        @Override
        public void messageArrived(String topic, MqttMessage message) throws Exception {
            String receivedMessage = new String(message.getPayload());
            Log.d("Received Message", "Topic: " + topic + ", Message: " + receivedMessage);

            if (topic.equals("hub/status/app/8xff")){
                Typedef.Buffer buff = Typedef.Buffer.parseFrom(message.getPayload());
                String controller = String.valueOf(buff.getCotroller());
                if ("Hub".equals(controller)){
                    Typedef.Buffer.Builder bufferBuilder = Typedef.Buffer.newBuilder()
                            .setMacHub("8xff")
                            .setSender(Typedef.User_t.valueOf("App"))
                            .setReceiver(Typedef.User_t.valueOf("Server"))
                            .setCotroller(Typedef.User_t.valueOf("Hub"));

                    for (Device device : myList) {
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
                    String buff_str = buff.toString();
                    System.out.println(buff_str);
                    byte[] mess = buffer.toByteArray();
                    mqttHandler.publish(TOPIC_DEVICE, mess);
                }
                else{
                    String mac = buff.getVpn().getMac();
                    boolean status = buff.getVpn().getStatus();
                    //mac_text.setText("Mac: " + mac);
                }
            }
        }
        @Override
        public void deliveryComplete(IMqttDeliveryToken token) {

        }
    }
}