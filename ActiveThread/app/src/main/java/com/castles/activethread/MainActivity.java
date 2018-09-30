package com.castles.activethread;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
import android.os.Handler;
import android.util.Log;

public class MainActivity extends AppCompatActivity {

    public static final String TAG = "MainActivity";
    public int flag = 10;
    protected Handler mHandler = new Handler();
    protected Runnable mGetPin = new Runnable() {
    @Override
    public void run() {
        try {
            while(0 < --flag) {
                getbuf();
                Thread.sleep(1000);
                Log.d(TAG, "flag mute");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
    };

    protected Runnable mShowui = new Runnable() {
        @Override
        public void run() {
            stringFromJNI();
        }
    };

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        getSupportActionBar().hide();
        //tv.setText(stringFromJNI());
        mHandler.post(mGetPin);
        //mHandler.post(mShowui);
    }

    @Override
    public void onStop() {
        super.onStop();
    }

    @Override
    public void onDestroy() {
        Log.d(TAG, "on destroy");
        mHandler.removeCallbacks(mGetPin);
        //mHandler.removeCallbacks(mShowui);
        super.onDestroy();
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native void getbuf();
}
