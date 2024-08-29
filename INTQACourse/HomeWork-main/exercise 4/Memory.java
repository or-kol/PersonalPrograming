package com.company;

public class Memory {

    public static int integer;
    public static float decimal;
    public static String string;

    public static void add(int a) {
        integer += a;
    }
    public static void add(float a) {
        decimal += a;
    }
    public static void add(String a) {
        string += a;
    }
}
