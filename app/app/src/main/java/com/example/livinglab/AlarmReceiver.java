package com.example.livinglab;

import static com.example.livinglab.MainActivity.deviceList;
import static com.example.livinglab.MainActivity.gv;
import static com.example.livinglab.MainActivity.mqttHandler;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Date;

public class AlarmReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        String deviceName = intent.getStringExtra("deviceName");
        boolean deviceStatus = intent.getBooleanExtra("deviceStatus", false);
        long currentTime = System.currentTimeMillis();
        Log.d("Alarm Debug", "Alarm: " + new Date(currentTime) + " device: " + deviceName + " status: " + deviceStatus);
        updateDevice(context, deviceName, deviceStatus);
    }

    private void updateDevice(Context context, String deviceName, boolean deviceStatus) {

        for (int i = 0; i < deviceList.size(); i++) {
            Device device = deviceList.get(i);
            if (device.getName().equals(deviceName)) {
                device.setStatus(deviceStatus);
                if (device.getDevice_type().equals("Led")){
                    device.setImg(device.isStatus() ? R.drawable.led_on : R.drawable.led_off);
                }
                else{
                    device.setImg(device.isStatus() ? R.drawable.switch_on : R.drawable.switch_off);
                }
                updateDeviceImageInGridView(i, device.getImg());
                sendDeviceStatus(device);

                break;
            }
        }
    }

    private void updateDeviceImageInGridView(int index, int imgRes) {

            View itemView = gv.getChildAt(index);
            if (itemView != null) {
                ImageView deviceImg = itemView.findViewById(R.id.device_img);
                deviceImg.setImageResource(imgRes);
            }
    }

    private void sendDeviceStatus(Device device) {
        byte[] message = device.toBuffer().toByteArray();
        System.out.println(device.toBuffer());
        mqttHandler.publish("hub/control/app/8xff", message);
    }
}
