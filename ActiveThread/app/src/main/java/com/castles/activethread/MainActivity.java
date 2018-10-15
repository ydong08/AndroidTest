package com.castles.activethread;

import android.support.constraint.ConstraintLayout;
import android.support.constraint.ConstraintSet;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;
import android.util.Log;
import java.util.Date;
import android.view.WindowManager;
import android.content.Context;
import android.os.Environment;

public class  MainActivity extends AppCompatActivity {

    public static final String TAG = "MainActivity";
    public static int width = 0;
    public static int height = 0;
    public ConstraintLayout layout;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        ImageView imv = (ImageView) findViewById(R.id.bmp);
        TextView tv = new TextView(this);
        EditText et = new EditText(this);
        //getSupportActionBar().hide();
        // get screen property
        getAndroidScreenProperty();

        // set text position
        tv.setX(80);
        tv.setY(200);
        tv.setHeight(60);
        tv.setBackgroundColor(0xF5F5F5);
        tv.setGravity(1);
        tv.setText(onTestJava());

        et.setHint("0.0");
        et.setX(80);
        et.setY(300);

        Log.i(TAG, "getFilesDir= " + getFilesDir());  //app的目录
        Log.i(TAG, "getExternalFilesDir= " + getExternalFilesDir("ActiveThread").getAbsolutePath());

        Log.i(TAG, "getDataDirectory= " + Environment.getDataDirectory());
        Log.i(TAG, "GetExternalStorageDirectory: " + Environment.getExternalStorageDirectory());

    }

    @Override
    public void onStop() {
        super.onStop();
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
    }

    public String onTestJava() {
        Date dt = new Date();
        Log.d(TAG, "Date: " + dt.toString());
        return dt.toString();
    }

    public void getAndroidScreenProperty(){
        WindowManager wm = (WindowManager) this.getSystemService(Context.WINDOW_SERVICE);
        DisplayMetrics dm = new DisplayMetrics();
        wm.getDefaultDisplay().getMetrics(dm);
        width = (int)(dm.widthPixels/dm.density)/2;
        height = (int)(dm.heightPixels/dm.density)/2;
        Log.d(TAG, "WidthP: " + dm.widthPixels);
        Log.d(TAG, "HeightP: " + dm.heightPixels);
        Log.d(TAG, "Width: " + (int)(dm.widthPixels/dm.density));
        Log.d(TAG, "Height: " + (int)(dm.heightPixels/dm.density));
        Log.d(TAG, "Density: " + dm.density);
        Log.d(TAG, "DPI: " + dm.densityDpi);
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}



