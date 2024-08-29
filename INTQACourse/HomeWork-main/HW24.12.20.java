package com.company;

public class Main {

    public static void main(String[] args) {
        
        //-- 1. create an array of double numbers with these numbers: 0.9, -6.5555, 3.24, 10.11, 20.35
        //-- 1.1. print the first element
        //-- 1.2. print the last element
        //-- 1.3. print the middle element
        //-- 1.4. write a for loop which prints all the element in the array
        //-- 1.5. write a for loop which prints all the element in the array in reverse
        //-- 1.6. use scanner to read a double number from the user. print all the elements in the array which are bigger than the user-number
        double[] doubles_arr = {0.9, -6.5555, 3.24, 10.11, 20.35};

        System.out.println(String.format("first: %g  ;  middle: %g  ;  last: %g", doubles[0], doubles[2], doubles[4]));

        for (int i = 0; i < doubles_arr.length; i++) {
            System.out.println(doubles_arr[i]);
        }

        for (int i2 = doubles_arr.length - 1; i2 >= 0; i2--) {
            System.out.println(doubles_arr[i2]);
        }

        System.out.println("Please enter a number: ");
        double big = s.nextInt();
        for (int i3 = 0; i3 < doubles_arr.length; i3++) {
            if (big < doubles_arr[i3])
            System.out.println(doubles_arr[i3]);
        }


        //-- 2. create an array A of integer numbers with these numbers: 4, 10, 20, 40, 1000
        //-- 2.1. create a second array B with these numbers: 0, 0, 0, 0, 0
        //-- 2.2. copy all elements from A to B

        int[] integers_a_arr = {4, 10, 20, 40, 1000};
        int[] integers_b_arr = {0, 0, 0, 0, 0};
        for (int i4 = 0; i4 < integers_b_arr.length; i4++) {
            integers_b_arr[i4] = integers_a_arr[i4];
            System.out.println(integers_b_arr[i4]);
        }


        //-- ***crazy etgar:
        //-- create an array of numbers: 1, 3, 5, 8, 8, 5, 3, 1
        //-- check if the array is a polindrom (which in this case it is)
        //-- polindrom = all elements are repeated in a reverse order:
        //-- here it is polidrom since --> 1 3 5 8 are reverse equal to 8 5 3 1
        //-- another polindrom: 3 4 6 9 9 6 4 3
        //-- not polindrom: 1 3 5 6 5 3 1 --> since 6 is not repeated
        
        int[] numbers_arr = {1, 3, 5, 8, 8, 5, 3, 1};

        int i6 = numbers_arr.length - 1;
        int counter = 0;
        for (int i5 = 0; i5 < numbers_arr.length / 2; i5++) {
            if (numbers_arr.length % 2 != 0) {
                break;
            }
            if (numbers_arr[i5] == numbers_arr[i6]) {
                counter++;
            }
            i6--;
        }

        if (counter == numbers_arr.length / 2) {
            System.out.println("the array is a palindrome!!");
        }
        else {
            System.out.println("the array is not a palindrome!!");
        }

    }
}
