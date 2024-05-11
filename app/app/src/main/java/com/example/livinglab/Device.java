package com.example.livinglab;

public class Device {
    private int img;
    private String name;
    private long mac;
    private boolean status;
    private String controller;
    private String device_type;
    public Device(int img, String name, long mac, boolean status, String controller, String device_type) {
        this.img = img;
        this.name = name;
        this.mac = mac;
        this.status = status;
        this.controller = controller;
        this.device_type = device_type;
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
}