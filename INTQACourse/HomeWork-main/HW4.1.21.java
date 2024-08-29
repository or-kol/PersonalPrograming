package com.company;

import java.util.Random;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        Random r = new Random();

        
        //1. Create a function that prints "hello world" , call it from main
        printHelloWorld();

        //2. Create a function that prints all numbers from 1 to 100, call it from main
        print1To100();

        //3. Create a function that inputs a number and prints if the number is even (zugi) or not, call it from main
        inputNamberPrintIfEvenOrNot(r);

        //4. **etgar: input the number from main instead of inside the function
        // not sure if that is what you meant:
        System.out.println("Please input a number: ");
        int user_num2 = s.nextInt();
        inputNumberPrintIfEvenOrNot2(user_num2);

        //5. what is the difference between "step over" and "step into" ?
        // in the debugger step into means getting into the function to follow it step by step, step over means to activate the function but not follow it step by step.

        //6. if you define int x inside main and int x inside a function , it is the same x? why?
        // it's not the same X, since the variable is relevant just to the scope it was created in.

        //7. ***etgarCreate function A() and call it from main, inside function A() call function B(), inside function B() call function A()
        //   what happend? why do you think?
        a();
        b();
        // the functions call to each other every time it's activated, so it will each function will run at it's turn (when it's called) until the 
        // system is overflow and it crushes.


    }

    private static void b() {
        System.out.println("ZYX");
        a();
    }

    private static void a() {
        System.out.println("ABC");
        b();
    }

    private static void inputNumberPrintIfEvenOrNot2(int user_num2) {
        if (user_num2 % 2 == 0) {
            System.out.println("The number is even");
        } else {
            System.out.println("The number is not even");
        }
    }

    private static void inputNamberPrintIfEvenOrNot(Random r) {
        int user_num = r.nextInt(100) + 1;
        if (user_num % 2 == 0) {
            System.out.println("The number is even");
        }
        else {
            System.out.println("The number is not even");
        }
    }

    private static void print1To100() {
        for (int ind2 = 1; ind2 <= 100; ind2++) {
            System.out.println(ind2);
        }
    }

    private static void printHelloWorld() {
        System.out.println("Hello world!");
    }



}
