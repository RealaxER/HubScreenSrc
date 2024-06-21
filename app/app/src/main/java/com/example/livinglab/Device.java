package com.example.livinglab;

import android.widget.ImageView;

public class Device {
    private int img;
    private String name;
    private long mac;
    private boolean status;
    private String controller;
    private String device_type;
    private int ep;
    public Device(int img, String name, long mac, boolean status, String controller, String device_type, int ep) {
        this.img = img;
        this.name = name;
        this.mac = mac;
        this.status = status;
        this.controller = controller;
        this.device_type = device_type;
        this.ep = ep;
    }

    public int getEp() {
        return ep;
    }

    public void setEp(int ep) {
        this.ep = ep;
    }

    public int getImg() {
        return img;
    }

    public void setImg(int img) {
        this.img = img;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public long getMac() {
        return mac;
    }

    public void setMac(long mac) {
        this.mac = mac;
    }

    public boolean isStatus() {
        return status;
    }

    public void setStatus(boolean status) {
        this.status = status;
    }

    public String getController() {
        return controller;
    }

    public void setController(String controller) {
        this.controller = controller;
    }

    public String getDevice_type() {
        return device_type;
    }

    public void setDevice_type(String device_type) {
        this.device_type = device_type;
    }

    public Typedef.Buffer toBuffer() {
        Typedef.Buffer.Builder bufferBuilder = Typedef.Buffer.newBuilder()
                .setMacHub("8xff")
                .setSender(Typedef.User_t.App)
                .setReceiver(Typedef.User_t.Server)
                .setCotroller(Typedef.User_t.valueOf(this.controller));

        if (this.device_type.equals("Led")) {
            Typedef.Led_t.Builder ledBuilder = Typedef.Led_t.newBuilder()
                    .setName(this.name)
                    .setMac(this.mac)
                    .setEp(this.ep)
                    .setStatus(this.status);
            bufferBuilder.addLed(ledBuilder);
        } else if (this.device_type.equals("Switch")) {
            Typedef.Sw_t.Builder swBuilder = Typedef.Sw_t.newBuilder()
                    .setName(this.name)
                    .setMac(this.mac)
                    .setEp(this.ep)
                    .setStatus(this.status);
            bufferBuilder.addSw(swBuilder);
        }

        return bufferBuilder.build();
    }
}