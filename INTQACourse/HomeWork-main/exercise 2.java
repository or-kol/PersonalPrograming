package com.company;

import java.util.Random;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        Random r = new Random();

        //Part 1
        //2.              0    1    2    3    4
        int[] arr_num = {101, 102, 103, 104, 105};


        //3.
        int[] arr_num3 = {2, 4, 6};
        System.out.println(String.format("second: %d ; last: %d", arr_num3[1], arr_num3[2]));


        //4.
        int[] arr_num4 = {1, 2, 3, 4};
        System.out.println(String.format("the last number is: %d", arr_num4[arr_num4.length - 1]));


        //5.
        int[] arr_empt = new int[20];


        //6.
        String[] arr_str = {"Welcome", "To", "Java"};


        //7.
        int[] arr_num5 = {-1, -2, -3, -4, -5};
        for (int i = 0; i < arr_num5.length; i++) {
            System.out.println(arr_num5[i]);
        }


        //8.
        int[] arr_num6 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (int i2 = 0; i2 < arr_num6.length; i2++) {
            if (arr_num6[i2] % 2 == 0) {
                System.out.println(arr_num6[i2]);
            }
        }


        //9.
        for (int i3 = arr_num6.length - 1; i3 >= 0; i3--){
            if (arr_num6[i3] % 2 == 0) {
                System.out.println(arr_num6[i3]);
            }
        }


        //10.
        int[] arr_num7 = new int[3];
        for (int i4 = 0; i4 < arr_num7.length; i4++) {
            System.out.println("Please input a number: ");
            arr_num7[i4] = s.nextInt();
        }


        //11.
        int[] arr_num8 = new int[5];
        for (int i5 = 0; i5 < arr_num8.length; i5++) {
            arr_num8[i5] = r.nextInt(50) + 1;
            System.out.println(arr_num8[i5]);
        }


        //12.
        int count = 0;
        for (int i6 = 0; i6 < arr_num8.length; i6++) {
            if (arr_num8[i6] % 2 == 0) {
                count++;
            }
        }
        if (count == arr_num8.length) {
            System.out.println("All numbers are even");
        } else {
            System.out.println("Not all numbers are even");
        }
        


        //13.
        int[] arr_num9_a = {3, 5, 4, 6, 8};
        int[] arr_num9_b = {3, 5, 4, 6, 8};

        int count2 = 0;
        if (arr_num9_a.length == arr_num9_b.length) {
            for (int i7 = 0; i7 < arr_num9_a.length; i7++) {

                if (arr_num9_a[i7] == arr_num9_b[i7]) {
                    count2++;
                } else {
                    break;   
                }
            if (count2 == arr_num9_a.length) {
                System.out.println("the arrays are identical");
            }
        }


        //14.
        int[] arr_num10_a = {6, 4, 9};
        int[] arr_num10_b = new int [3];
        for (int i8 = 0; i8 < arr_num10_b.length; i8++) {
            System.out.println(String.format("please input digit #%d", i8 + 1));
            arr_num10_b[i8] = s.nextInt();
        }

        int count14 = 0;
        for (int i9 = 0; i9 < arr_num10_a.length; i9++) {
            if (arr_num10_a[i9] == arr_num10_b[i9]) {
                count14++;
            } else {
                break;
            }
            }
        if (count14 == arr_num10_a.length) {
            System.out.println("Access granted!!");
        }
        else {
            System.out.println("Wrong!!");


        //15.
        System.out.println("Please enter a word: ");
        String word = s.nextLine();
        System.out.println(word.length());


        //16.
        String[] doc = {"dog", "cat", "home", "car"};
        int word_count = 0;
        for (int i10 = 0; i10 < doc.length; i10++) {
            word_count += doc[i10].length();
        }
        System.out.println(String.format("The document contains %d letters", word_count));


        //17.
        String[] student = new String[5];
        int[] grade = new int[5];
        for (int i11 = 0; i11 < student.length; i11++) {
            System.out.println("Please input student's name: ");
            student[i11] = s.next();
            System.out.println("Please input student's grade: ");
            grade[i11] = s.nextInt();
        }
        for (int i12 = 0; i12 < student.length; i12++) {
            System.out.print(String.format("name: %s  ;  grade: %d", student[i12], grade[i12]));
            System.out.println();
        }


        //18.
        int[] arr_num11 = {1, 6, 30, 4, -25, 10, 25, 15, 17, 14, -10};
        int small = 0;
        int big = 0;
        for (int i13 = 0; i13 < arr_num11.length; i13++) {
            if (arr_num11[i13] > big){
                big = arr_num11[i13];
            }
            if (arr_num11[i13] < small) {
                small = arr_num11[i13];
            }
        }
        System.out.println(String.format("The largest number is: %d", big));
        System.out.println(String.format("The smallest number is: %d", small));


        //19.
        String[] arr_word2 = {"sin", "tease", "wheel", "cars", "mind", "subsequent", "attach", "undress", "request", "past"};
        System.out.println("Please input a word: ");
        String user_word = s.next();

        int count19 = 0;
        for (int i14 = 0; i14 < arr_word2.length; i14++) {
            if (arr_word2[i14].equals(user_word)) {
                System.out.println(String.format("the word exist in place %d", i14));
                count19++;
            }
        }
        if (count19 == 0) {
            System.out.println(String.format("The array doesn't include the word %s", user_word));
        }


        //20
        int[] arr_num20a = {1, 2, 3, 4, 5};
        int[] arr_num20b = new int[arr_num20a.length];
        int x = arr_num20a[arr_num20a.length - 1];
        for (int i20 = 1; i20 < arr_num20a.length; i20++) {
            arr_num20b[i20] = arr_num20a[i20 - 1];
            arr_num20b[0] = arr_num20a[arr_num20a.length - 1];
            //System.out.println(arr_num20b[i20]);
        }
        for (int i20b = 0; i20b < arr_num20a.length; i20b++) {
            System.out.println(arr_num20b[i20b]);
        }


        //21.
        String[] arr_hang_a = {"h", "e", "l", "l", "o"};
        String[] arr_hang_b = {"_", "_", "_", "_", "_"};
        int count21 = 0;
        for (int i21_a = 0; i21_a < 30; i21_a++){
            System.out.println(String.format("please input guess #%d: ", i21_a + 1));
            String user_guess = s.next();
            for (int i21_b = 0; i21_b < arr_hang_b.length; i21_b++) {
                if (arr_hang_a[i21_b].equals(user_guess)) {
                    System.out.println("Yes");
                    arr_hang_b[i21_b] = arr_hang_a[i21_b];
                    count21++;
                } else {
                    System.out.println("No");
                }
            }
            for (int i21_c = 0; i21_c < arr_hang_b.length; i21_c++) {
                System.out.print(arr_hang_b[i21_c]);
            }
            System.out.println();
            if (count21 == arr_hang_b.length) {
                break;
            }
        }




        //Part 2
        //22.
        for (int i22 = 0; i22 < 5; i22++) {
            for (int i22_b = 1; i22_b < 11; i22_b++) {
                System.out.print(i22_b);
                System.out.print(" ");
            }
            System.out.println();
        }


        //23.
        String[] arr_days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        for (int i23_a = 0; i23_a < 4; i23_a++) {
            for (int i23_b = 0; i23_b < arr_days.length; i23_b++) {
                System.out.print(arr_days[i23_b]);
                System.out.print(" ");
            }
            System.out.println();
        }


        //24.
        for (int i24_a = 1; i24_a <= 10; i24_a++) {
            int power = 1;
            for (int i24_b = 1; i24_b <= 5; i24_b++) {
                power *= i24_a;
                System.out.println(String.format("%d^%d=%d", i24_a, i24_b, power));
            }
            System.out.println();
        }


        //25.
        for (int i25_a = 2; i25_a <= 10; i25_a++) {
            int fact = i25_a;
            for (int i25_b = 2; i25_b <= i25_a - 1; i25_b++) {
                fact *= i25_b;
            }
            System.out.println(fact);
            System.out.println();
        }


        //26.
        System.out.println("please enter a number for length: ");
        int len = s.nextInt();
        System.out.println("please enter a number for width: ");
        int wid = s.nextInt();
        for (int i26_a = 0; i26_a < len; i26_a++) {
            for (int i26_b = 0; i26_b < wid; i26_b++) {
                System.out.print("*");
            }
            System.out.println();
        }


        //27.
        System.out.println("please enter a number for length: ");
        int[] len27 = new int[s.nextInt()];
        System.out.println("please enter a number for width: ");
        String[] wid27 = new String[s.nextInt()];

        for (int i27_a = 0; i27_a < wid27.length; i27_a++) {
            wid27[i27_a] = "*";
        }
        for (int i27_b = 0; i27_b < len27.length; i27_b++) {
            if (i27_b == 0 || i27_b == len27.length - 1) {
                for (int i27_c = 0; i27_c < wid27.length; i27_c++) {
                    System.out.print(wid27[i27_c]);
                    System.out.print(" ");
                }
                System.out.println();
            }
            else {
               // for (int i27_c = 0; i27_c < wid27.length; i27_c++) {
                    System.out.print(wid27[0]);
                System.out.print(" ");
                    for (int i27_d = 1; i27_d < wid27.length - 1; i27_d++) {
                        System.out.print("  ");
                    }
                    System.out.print(wid27[wid27.length - 1]);
                    System.out.print(" ");
                //}
                System.out.println();
            }
        }


        //28.
        String[] arr_asterisk = {"    *", "   * *", "  * * *", " * * * *", "* * * * *"};
        for (int i28 = 0; i28 < arr_asterisk.length; i28++) {
            System.out.print(arr_asterisk[i28]);
            System.out.println();
        }


    }
}
