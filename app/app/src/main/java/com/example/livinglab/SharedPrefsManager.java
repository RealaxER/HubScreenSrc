package com.example.livinglab;

import android.content.Context;
import android.content.SharedPreferences;

import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.lang.reflect.Type;
import java.util.ArrayList;
import java.util.List;

public class SharedPrefsManager {
    private static final String PREF_NAME = "MyPrefs";
    private static final String DEVICE_LIST_KEY = "deviceList";

    private SharedPreferences sharedPreferences;

    public SharedPrefsManager(Context context) {
        sharedPreferences = context.getSharedPreferences(PREF_NAME, Context.MODE_PRIVATE);
    }

    public void saveDeviceList(ArrayList<Device> deviceList) {
        SharedPreferences.Editor editor = sharedPreferences.edit();
        Gson gson = new Gson();
        String json = gson.toJson(deviceList);
        editor.putString(DEVICE_LIST_KEY, json);
        editor.apply();
    }

    public ArrayList<Device> loadDeviceList() {
        String json = sharedPreferences.getString(DEVICE_LIST_KEY, null);
        if (json != null) {
            Gson gson = new Gson();
            Type type = new TypeToken<ArrayList<Device>>() {}.getType();
            return gson.fromJson(json, type);
        }
        return new ArrayList<>();
    }
}
