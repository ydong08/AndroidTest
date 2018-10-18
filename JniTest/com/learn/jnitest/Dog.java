package com.learn.jnitest;

import java.lang.System;
import com.learn.jnitest.Animal;

public class Dog extends Animal {
    protected String name = "super";
    public Dog (String str) {
        super(str);
        name = "super" + str;
        System.out.println("Dog init");
    }

    @Override
    public void run(String str) {
        System.out.println("Dog: " + name);
    }
}
