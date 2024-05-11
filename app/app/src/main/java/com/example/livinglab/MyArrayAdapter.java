package com.example.livinglab;

import android.app.Activity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import java.util.ArrayList;

public class MyArrayAdapter extends ArrayAdapter<Device> {
    Activity context;
    int IdLayout;
    ArrayList<Device> myList;

    public MyArrayAdapter(Activity context, int idLayout, ArrayList<Device> myList) {
        super(context, idLayout, myList);
        this.context = context;
        IdLayout = idLayout;
        this.myList = myList;
    }

    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        LayoutInflater myflater = context.getLayoutInflater();
        convertView = myflater.inflate(IdLayout, null);
        Device mydevice = myList.get(position);
        ImageView led_img = convertView.findViewById(R.id.device_img);
        led_img.setImageResource(mydevice.getImg());
        TextView led_name = convertView.findViewById(R.id.led_name);
        led_name.setText(mydevice.getName());
        return convertView;
    }
}
