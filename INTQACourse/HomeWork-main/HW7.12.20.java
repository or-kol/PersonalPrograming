package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        
        // 1. input two int numbers from the user, check if they are both zeros, if so print "both zeroes" otherwise print "not both zeroes"
        System.out.println("Enter a first number: ");
        int first_number = s.nextInt();

        System.out.println("Enter a second number: ");
        int second_number = s.nextInt();

        if (first_number == 0 && second_number == 0) {
            System.out.println("both zeroes");
        }
        else {
            System.out.println("not both zeroes");
        }

        // 2. input a,b,c (int) check if all numbers are different from each-other, if so print "diff" otherwise print "similar"
        System.out.println("Enter a number for a: ");
        int a = s.nextInt();

        System.out.println("Enter a number for b: ");
        int b = s.nextInt();

        System.out.println("Enter a number for c: ");
        int c = s.nextInt();

        if (a != b && a != c && b != c) {
            System.out.println("diff");
        }
        else {
            System.out.println("similar");
        }

        // 3. input x,y,z (float) check and print how many of them are positive
        System.out.println("Enter a number for x: ");
        float x = s.nextFloat();

        System.out.println("Enter a number for y: ");
        float y = s.nextFloat();

        System.out.println("Enter a number for z: ");
        float z = s.nextFloat();

        if (x > 0) {
            x = 1;
        }
        else {
            x = 0;
        }
        if (y > 0) {
            y = 1;
        }
        else {
            y = 0;
        }
        if (z > 0){
            z = 1;
        }
        else {
            z = 0;
        }

        System.out.println(x + y + z);

        
        // 4. input l, m, n. print the biggest
        System.out.println("Enter a number for l: ");
        int l = s.nextInt();

        System.out.println("Enter a number for m: ");
        int m = s.nextInt();

        System.out.println("Enter a number for n: ");
        int n = s.nextInt();

        if (l > m && l > n) {
            System.out.println("l is the biggest!");
        }
        else if (m > n) {
            System.out.println("m is the biggest!");
        }
        else {
            System.out.println("n is the biggest!");
        }
        
    }
}
