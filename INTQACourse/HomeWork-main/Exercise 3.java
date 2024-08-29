package com.company;

import java.util.Random;
import java.util.Scanner;

public class Main {

    static Scanner s = new Scanner(System.in);
    static Random r = new Random();

    static String magicWorld = "Magic World";

    public static void main(String[] args) {

        //Q3
        greet();


        //Q4
        printNum(6);


        //Q5
        for (int i = 1; i <= 10; i++) {
            printNum(i);
        }


        //Q6
        int k = 5;
        changeNumber(k);
        System.out.println(String.format("the value of 'k' is: %d", k));
        // the value of 'K' is still 5, since the addition took place in a different function and we didn't print the returned value.


        //Q7
        multiply(5,7);
        multiply(3,6);
        multiply(5,4);


        //Q8
        calc(3, '+', 5);
        calc(3, '-', 5);


        //Q9
        System.out.println(String.format("the average is: %f", avg9(20, 2, 12)));


        //Q10
        int[] arr10 = {1, 2, 3};
        System.out.println(trueOrFalse(arr10, 3));


        //Q11
        dividers(10);


        //Q12
        hello();


        //Q13
        // when we want do overloading - use the same function name for different variables.


        //Q14
        int x14 = 0;
        float y14 = 0f;
        double z14 = 0;
        numberType(x14);
        numberType(y14);
        numberType(z14);


        //Q15
        getScanner();


        //Q16
        int[] arr16 = {1, 2, 3, 4, 5, 6, 7, 8};
        System.out.println(randomize(arr16));


        //Q17
        System.out.println(addAt("a"));


        //Q18
        // creating a variable outside the functions can be used in every function we want.
        // creating a variable inside functions can be used only in the scope of the relevant function.


        //Q19
        printWold();
        changeWorld("abc");
        System.out.println(magicWorld);
        //the value of magicWorld changed.


        //Q20
        int[] arr_20 = {2, 6, 7, 8, 34, 16};
        multiplyEven(arr_20);
        addOne(arr_20);
        setZero(arr_20);
        // the original array changed.


        //Q21
        System.out.println(String.format("the sum of the digits is: %d", sumOfDigits(1568452)));


        //Q22
        char[] password_arr = {'p', 'a', 's', 's', '1', '2', '3', '4'};
        char[] password_arr2 = {'p', 'a', 's', 's', '1', '2', '3', '4', '4'};
        char[] password_arr3 = {'p', 'a', 's', 's', '1', '2', '3'};
        char[] password_arr4= {'p', 'a', 's', 's', 's', 's', 's', 's'};
        char[] password_arr5 = {'1', '1', '1', '1', '1', '2', '3', '4'};
        System.out.println(passwordChek(password_arr));
        System.out.println(passwordChek(password_arr2));
        System.out.println(passwordChek(password_arr3));
        System.out.println(passwordChek(password_arr4));
        System.out.println(passwordChek(password_arr5));


        //Q23
        int[][] matrix = new int[3][3];
        rndMatrix(matrix);
        sumMatrix(matrix);


        //Q24
        // recursion is when calling to a function from itself.


        //Q25
        System.out.println(calcFactorial(10));

    }


    //Q25
    public static int calcFactorial (int a) {
        int fact = 0;
        if (a >= 2) {
            fact = a * calcFactorial(a - 1);
        }
        else {
            fact = 1;
        }
        return fact;
    }


    //Q23
    public static void rndMatrix (int[][] fn_matrix) {
        for (int i = 0; i < fn_matrix.length; i++) {
            for (int i2 = 0; i2 < fn_matrix.length; i2++) {
                fn_matrix[i][i2] = r.nextInt(100) + 1;
                System.out.print(fn_matrix[i][i2] + " ");
            }
        }
        System.out.println();
    }

    public static void sumMatrix (int[][] fn_matrix) {
        int sum = 0;
        for (int i = 0; i < fn_matrix.length; i++) {
            for (int i2 = 0; i2 < fn_matrix.length; i2++) {
                sum += fn_matrix[i][i2];
            }
        }
        System.out.println(String.format("the sum of the numbers in the matrix is: %d", sum));
    }


    //Q22
    public static String passwordChek (char[] fn_arr1, String a) {
        int count_digit = 0;
        int count_letter = 0;
        if (fn_arr1.length >= 8) {
            for (int i = 0; i < fn_arr1.length; i++) {
                if (Character.isDigit(fn_arr1[i])) {
                    count_digit++;
                } else if (Character.isLetter(fn_arr1[i])) {
                    count_letter++;
                }
                if (count_digit > 0 && count_letter > 0) {
                    break;
                }
            }
        }
        return count_digit > 0 && count_letter > 0 ? "true" : "false";
    }


    //Q21
    public static int sumOfDigits (int a) {
        int sum = 0;
        int x = a;
        for (int i = 1; i <= String.valueOf(a).length(); i++) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }


    //Q20
    public static void multiplyEven (int[] fn_arr) {
        for (int i = 0; i < fn_arr.length; i++) {
            if (fn_arr[i] % 2 == 0) {
                System.out.println(String.format("%d * 2 = %d", fn_arr[i], fn_arr[i] * 2));
            }
        }
    }

    public static void addOne (int[] fn_arr) {
        fn_arr[fn_arr.length-1]++;
        System.out.println(fn_arr[fn_arr.length-1]);
    }

    public static void setZero (int[] fn_arr) {
        for (int i = 0; i < fn_arr.length; i++) {
            if (fn_arr[i] % 2 != 0) {
                fn_arr[i] = 0;
            }
            System.out.println(fn_arr[i]);
        }

    }

    //Q19
    public static void printWold () {
        System.out.println(magicWorld);
    }
    public static void changeWorld (String a) {
        magicWorld = a;
    }


    //Q17
    public static String addAt (String a) {
        return a + "@@@" + addAsterisk() + addHash();
    }
    public static String addAsterisk () {
        return "**";
    }
    public static String addHash () {
        return "#";
    }


    // Q16
    public static int randomize (int[] fn_arr) {
        int i = r.nextInt(fn_arr.length);
        return fn_arr[i];
    }


    // Q15
    public static Scanner getScanner () {
        Scanner scanner = new Scanner(System.in);
        return scanner;
    }


    //Q14
    public static void numberType (int a) {
        System.out.println("the type is integer");
    }
    public static void numberType (float a) {
        System.out.println("the type is float");
    }
    public static void numberType (double a) {
        System.out.println("the type is double");
    }


    //Q12
    public static void hello () {
        System.out.print("Hello");
        System.out.print(" ");
        world();
    }

    public static void world () {
        System.out.print("World");
    }


    //Q11
    public static void dividers (int a) {
        for (int i = 1; i < a; i++) {
            if (a % i == 0) {
                System.out.println(i);
            }
        }
    }


    //Q10
    public static String trueOrFalse (int[] fn_arr, int a) {
        int count = 0;
        for (int i = 0; i < fn_arr.length; i++) {
            if (fn_arr[i] == a) {
                count++;
                break;
            }
        }
        return count == 0 ? "false" : "true";
    }


    //Q9
    public static float avg9 (float a, float b, float c) {
        return (a + b + c) / 3;
    }


    //Q8
    public static void calc (int a, char sign, int b) {
        switch (sign) {
            case '+':
                System.out.println(a + b);
                break;
            case '-':
                System.out.println(a - b);
                break;
        }
    }


    //Q7
    public static void multiply (int a, int b) {
        System.out.println(a * b);
    }


    //Q6
    static public void changeNumber (int a) {
        a++;
    }


    //Q4
    public static void printNum (int a) {
        System.out.println(String.format("the number is: %d", a));
    }


    //Q3
    public static void greet () {
        System.out.println("Good Morning");
    }
}
