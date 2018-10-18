package com.learn.jnitest;

import java.lang.System;

public class Animal {
    protected String name = "Dog";
    public Animal(String str) {
        name = str;
        System.out.println("Animal init");
    }

    public void run(String str) {
        System.out.println("Animal: " + name);
    }
}


