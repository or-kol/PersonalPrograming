package com.company;

import java.util.Random;
import java.util.Scanner;

public class Main {

    static Scanner s = new Scanner(System.in);
    static Random r = new Random();

    public static void main(String[] args) {

        //1. Define Scanner in Main scope
        //2. Define Random in Main scope

        //3. Create a function getString which gets a String msg as parameter and returns a String
        //   println (msg)
        //   return a string input from the user (use Scanner)

        System.out.println(String.format("your name is : %s", getString("please enter you name: ")));


        //4. Create a function howManyDigits which gets an int as parameter and returns the number of digits (int)
        //   i.e. howManyDigits(985) -> will return 3
        //   i.e. howManyDigits(12343) -> will return 5
        //   **etgar : add another function with the same name (overloading) change the function output to return a String and get a float parameter and print digit before and after digit
        //   i.e. howManyDigits(5.444) -> will return *.***
        //   i.e. howManyDigits(235.4) -> will return ***.*

        System.out.println("please enter a number:");
        int a = s.nextInt();
        System.out.println(String.format("the number %d has %d digits", a, howManyDigits(a)));


        //5. Create a function isLonger which gets an int[] arr and int len and return true if the array length is bigger than len
        //   i.e. int[] arr = {1,2,3,4}
        //        isLonger(arr, 5) -> will return false
        //        isLonger(arr, 4) -> will return false
        //        isLonger(arr, 3) -> will return true
        //   create overloading for float[] and int len ...

        int[] arr_int = {1, 2, 3, 4};
        System.out.println(isLonger(arr_int, 3));

        float[] arr_float = {1.5f, 0.2f, 0.3f, -4.7f};
        System.out.println(isLonger(arr_float, 5));


        //6. Create a function arrayEqual which gets int[] , int[] and return true if both arrays are equal in size and content
        //   i.e. int[] arr1 = {1,2,3,4}
        //        int[] arr2 = {1,2,3,4}
        //        arrayEqual (arr1, arr2) -> will return true
        //   i.e. int[] arr1 = {1,2,3,4}
        //        int[] arr2 = {1,2,3}
        //        arrayEqual (arr1, arr2) -> will return false
        //   i.e. int[] arr1 = {1,2,3,4}
        //        int[] arr2 = {4,3,2,1}
        //        arrayEqual (arr1, arr2) -> will return false

        int[] arr1 = {1, 2, 3, 4};
        int[] arr2 = {1, 2, 3, 4};
        System.out.println(arrayEqual(arr1, arr2));

        int[] arr1_2 = {1, 2, 3, 4};
        int[] arr2_2 = {1, 2, 3};
        System.out.println(arrayEqual(arr1_2, arr2_2));

        int[] arr1_3 = {1, 2, 3, 4};
        int[] arr2_3 = {4, 3, 2, 1};
        System.out.println(arrayEqual(arr1_3, arr2_3));
    }

    public static String arrayEqual (int[] fn_arr1, int[] fn_arr2) {
        int count = 0;
        if (fn_arr1.length == fn_arr2.length) {
            for (int i = 0; i < fn_arr1.length; i++) {
                if (fn_arr1[i] == fn_arr2[i]) {
                    count++;
                }
            }
        }
        return count == fn_arr1.length && count == fn_arr2.length ? "true" : "false";
    }

    public static String isLonger (int[] fn_arr, int len) {
        return fn_arr.length > len ? "True" : "false";
    }
    public static String isLonger (float[] fn_arr, int len) {
        return fn_arr.length > len ? "True" : "false";
    }

    public static int howManyDigits (int a) {
        return String.valueOf(a).length();
    }

    public static String getString (String msg) {
        System.out.println(msg);
        return s.next();
    }



}
