package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        
        //1. input two int numbers from the user a, b.
        // print a > b, or a < b or a == b
        // for example, if a = 3 and b = 4:
        // print "3 < 4"
        // for example, if a = 7 and b = 1:
        // print "7 > 1"
        // for example, if a = 9 and b = 9:
        // print "9 == 9"

        System.out.println("please enter a number for a and b: ");
        int a = s.nextInt();
        int b = s.nextInt();

        if (a > b) {
            System.out.println(String.format("%d > %d", a, b));
        }
        else if (a < b) {
            System.out.println(String.format("%d < %d", a, b));
        }
        else {
            System.out.println(String.format("%d = %d", a, b));
        }



        // 2. write a loop which prints all the numbers from 5 to 10

        int d = 5;

        while (d < 11){
            System.out.println(d);
            d++;
        }



        // 3. write a loop which inputs a number from the user until a number bigger than 100 is given

        System.out.println("please enter a number for e: ");
        int e = s.nextInt();

        while (e < 101){
            System.out.println("please enter a number bigger than 100!");
            e = s.nextInt();
        }

        System.out.println("the number you entered is bigger than 100!");



        // 4. *etgar: print all the even numbers from 4 to 100.
        // should be like: 4, 6, 8, 10, ... 100

        System.out.println("please enter a number for f: ");
        int f = 4;

        while (f < 101) {
            System.out.println(f);
            f += 2;
        }
        


        // 5. *etgar: input two numbers from the user until the two numbers are the same

        System.out.println("please enter a number for g and h: ");
        int g = s.nextInt();
        int h = s.nextInt();

        while (g != h) {
            System.out.println("g does not equals to h! please try again!");
            g = s.nextInt();
            h = s.nextInt();
        }

        System.out.println("g equals to h"); 
    }
}
