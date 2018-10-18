package com.learn.jnitest;

import java.lang.System;
class MyClass {}

public class Hello {
/*
    // 用于测试的父类和子类不能是内部类
    class Animal {
        protected String name = "Dog";
        public Animal(String str) {
            name = str;
            System.out.println("Animal init");
        }

        public void run(String str) {
            System.out.println("Animal: " + name);
        }
    }

    class Dog extends Animal {
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
*/ 
    static {
        String path = System.getProperty("java.library.path");
        System.out.println("library path: " + path);
        System.loadLibrary("hello");
    }

    public int len = 0;

    public String str = "str";

    public static String name = "binder";

    public void instanceMethod(String str, int i) {
        System.out.format("instanceMethod: %d -> %s\n", i, str);
        return ;
    }

    public static void classMethod(String str, int i) {
        System.out.format("classMethod: %d -> %s\n", i, str);
        return ;
    }
    public static void main(String[] args) {
        // hello
        System.out.println("enter main: " + hello("path"));

        // test
        byte b = 127;
        long l = 128L;
        short s = 129;
        String obj = "str";
        test(true, b, 'A', s, 130, l, 1.0f, 10.5, "china", obj, new MyClass(), new int[]{});

        // critical
        System.out.println("critical: " + critical("critical"));

        // region
        System.out.println("region: " + region("region"));

        // int array
        int[] arr = new int[20];
        for(int i = 0; i < 20; ++i){
            arr[i] = i;
        }
        System.out.println("sum: " + sumArray(arr));

        // 2d int array
        int arr2d[][] = new int[8][20];
        for(int i = 0; i < 8; ++i){
            for(int j = 0; j < 20; ++j){
                arr2d[i][j] = j;
            }
        }
        System.out.println("arr2d: " + sum2dArray(arr2d));

        // init int array
        int size = 4;
        int arr2d2[][] = initIntArray(size);
        for (int i = 0; i < size; ++i) {
            for  (int j = 0; j < size; ++j) {
                System.out.format("arr2d2[%d][%d] = %d\n", i, j, arr2d2[i][j]);
            }
        }
        // call java method
        callJavaInstanceMethod();
        callJavaStaticMethod();

        // access field
        Hello h = new Hello();
        System.out.format("- %s\n", Hello.name);
        System.out.format("Len: %d - %s\n", h.len, h.str);
        accessInstanceField(h);
        accessStaticField();
        System.out.format("- %s\n", Hello.name);
        System.out.format("Len: %d - %s\n", h.len, h.str);

        // call init method
        callClassInitMethod();

        System.out.println("end main");
    }

    public static native String hello(String name);
    public static native void test(boolean z, byte b, char c, short s, int n, long l, float f, double d, 
                                    String str, Object obj, MyClass m, int[] arr);
    public static native String critical(String str);

    public static native String region(String str);

    public static native int sumArray(int[] arr); 

    public static native int sum2dArray(int[][] arr);

    public static native int[][] initIntArray(int size);

    public static native void objArray(Object[] obj);

    public static native void callJavaStaticMethod();
    
    public static native void callJavaInstanceMethod();

    public static native void accessStaticField();

    public static native void accessInstanceField(Hello h);

    public static native void callClassInitMethod();
}



