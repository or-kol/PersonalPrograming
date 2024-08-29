package com.company;

import java.util.Random;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        Random r = new Random();



        //1. create a function called printBiggest with the following overloading:
        //   printBiggest() -- will print "I am the biggest of them all!"
        //   printBiggest(int a) -- will print a + " is biggest"
        //   printBiggest(int a, int b) -- will print the biggest of a and b + " is biggest"
        //   printBiggest(int a, int b, int c) -- will print the biggest of a and b and c+ " is biggest"
        printBiggest();
        printBiggest(10, 8);
        printBiggest(1, 2, 3);




        //2. create a function that accepts Scanner as an argument and inputs a float from the user
        //   hint: inputFromUser(Scanner s)

        inputFromUser(s);



        //3. create a function that accepts Random as an argument and prints a random number and also gets the min max range as parameters
        //   hint: createRandom(Random r, int min, in max)

        createRandom(r,500, 1000);



        //4. create a function that accepts an array of double, and also min max range as parameters
        //   hint: printInRange(double[] arr, double min, double max)
        //   the function will print all the array elements which are in the range
        //   for example:
        //   arr = { 0.5, 0.7, 5, -2, 12.5 }
        //   min = -4
        //   max = 0.5
        //   will print: 0.5, -2

        double[] arr_doubles = { 0.5, 0.7, 5, -2, 12.5 };
        printInRange(arr_doubles,-10,15);



        //   ** etgar: create a double[] array which will hold the number of elements in the range
        //   for example:
        //   arr = { 0.5, 0.7, 5, -2, 12.5 }
        //   min = -4
        //   max = 0.5
        //   result = { 0.5, -2 } --> the result array should be in size 2 since only two numbers were in range!!

        numberOfElementsInRange(arr_doubles, -10,15);

    }

    public static void numberOfElementsInRange(double[] fn_arr, double min, double max) {
        int count = 0;
        for (int i = 0; i < fn_arr.length; i++) {
            if (fn_arr[i] >= min && fn_arr[i] <= max) {
                count++;
            }
        }
        System.out.println(String.format("the new array size is %d", count));
    }

    public static void printInRange(double[] fn_arr, double min, double max) {
        for (int i = 0; i < fn_arr.length; i++) {
            if (fn_arr[i] >= min && fn_arr[i] <= max) {
                System.out.println(fn_arr[i]);
            }
        }
    }

    public static void createRandom(Random r, int min, int max) {
        int rna = r.nextInt(max - min) + min;
    }


    public static void inputFromUser(Scanner s) {
        System.out.println("please input a number: ");
        int user_num = s.nextInt();
    }


    public static void printBiggest() {
        System.out.println("I am the biggest of them all!");
    }
    public static void printBiggest(int a) {
        System.out.println(String.format("%d is the biggest of all!", a));
    }
    public static void printBiggest(int a, int b) {
        if (a > b) {
            System.out.println(String.format("%d is the biggest of all!", a));
        }
        else {
            System.out.println(String.format("%d is the biggest of all!", b));
        }
    }
    public static void printBiggest(int a, int b, int c) {
        if (a > b && a > c) {
            System.out.println(String.format("%d is the biggest of all!", a));
        }
        else if (b > c) {
            System.out.println(String.format("%d is the biggest of all!", b));
        }
        else {
            System.out.println(String.format("%d is the biggest of all!", c));
        }
    }







}
