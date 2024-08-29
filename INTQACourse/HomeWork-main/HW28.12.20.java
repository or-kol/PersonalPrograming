package com.company;

import java.util.Random;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        Random r = new Random();

        //Home work

        //1. input array size from user
        //create int array in the given size
        //populate the array with random numbers
        //sum the array
        //print the average number
        System.out.println("Please input array size: ");
        int[] arr_int3 = new int[s.nextInt()];
        for (int i9 = 0; i9 < arr_int3.length; i9++) {
            arr_int3[i9] = r.nextInt(100);
        }

        int sum2 = 0;
        for (int i10 = 0; i10 < arr_int3.length; i10++) {
            sum2 += arr_int3[i10];
        }
        float avg = sum2 / arr_int3.length;
        System.out.println(String.format("The average of the class is: %g", avg));


        //2. create an array of 5 Strings (hint: String[] word = new String[5])
        //create a for loop and input words from the user into the array
        //now print the array in a for loop
        //*** etgar: print the average length of the words, i.e.  hello java book pro about. the words length is  [5,4,4,3,5] => average=4.2
        
        String[] arr_string = new String[5];
        for (int i14 = 0; i14 < arr_string.length; i14++) {
            System.out.println("Please input a word: ");
            arr_string[i14] = s.next();
        }
        for (int i15 = 0; i15 < arr_string.length; i15++) {
            System.out.println(arr_string[i15]);
        }
        int sum_of_letters = 0;
        float avg_of_letters = 0;
        for (int i16 = 0; i16 < arr_string.length; i16++) {
            sum_of_letters += arr_string[i16].length();
        }
        avg_of_letters = sum_of_letters / arr_string.length;
        System.out.println(String.format("the average of string length is: %g", avg_of_letters));


        //3. create int array A with random numbers (size of 5)
        //create int array B with random numbers (size of 5)
        //create int array C (size of 5) which each element will be the sum of A+B
        //for exmaple:
        //A [ 5, 8, 6, 2, 3]  -- random
        //B [ 3, 7, 8, 3, 1]  -- random
        //C [ 8,15,14, 5, 4]  -- sum
        
        int[] arr_random_a = new int[5];
        for (int i17 = 0; i17 < arr_random_a.length; i17++) {
            arr_random_a[i17] = r.nextInt(10) + 1;
            System.out.println(arr_random_a[i17]);
        }
        int[] arr_random_b = new int[5];
        for (int i18 = 0; i18 < arr_random_b.length; i18++) {
            arr_random_b[i18] = r.nextInt(10) + 1;
            System.out.println(arr_random_b[i18]);
        }
        int[] arr_random_c = new int[5];
        for (int i19 = 0; i19 < arr_random_c.length; i19++) {
            arr_random_c[i19] = arr_random_a[i19] + arr_random_b[i19];
        }

        //*etgar: create int array D which will contain the larger name from A or B
        //*D[ 5, 8, 8, 3, 3]
        int[] arr_random_d = new int[5];
        for (int i20 = 0; i20 < arr_random_d.length; i20++) {
            if (arr_random_a[i20] > arr_random_b[i20]) {
                arr_random_d[i20] = arr_random_a[i20];
            }
            else {
                arr_random_d[i20] = arr_random_b[i20];
            }
        }
        
        //*etgar: create in array E which will be concat of the array A and B
        //*E[ 5, 8, 6, 2, 3, 3, 7, 8, 3, 1]
        int[] arr_random_ab = new int[10];
        for (int i21 = 0; i21 < arr_random_ab.length / 2; i21++) {
            arr_random_ab[i21] = arr_random_a[i21];
        }
        int i23 = 0;
        for (int i22 = 5; i22 < arr_random_ab.length; i22++) {
            arr_random_ab[i22] = arr_random_b[i23];
            i23++;
        }
        for (int i24 = 0; i24 < arr_random_ab.length; i24++) {
            System.out.println(arr_random_ab[i24]);
        }
        
        
        //4. ***etgar crazy:
        //input number of classes from user
        //for each size input number of students
        //input all numbers from user
        //calculate the average of each class in an array
        //calculate the average of averages

        float sum_of_avg = 0;
        float total_avg = 0;
        System.out.println("Please input # of classes: ");
        int[] classes = new int[s.nextInt()];
        for (int i11 = 0; i11 < classes.length; i11++) {
            System.out.println(String.format("Please input number of student in class #%d: ", i11 + 1));
            int[] arr_grades = new int[s.nextInt()];
            for (int i12 = 0; i12 < arr_grades.length; i12++) {
                System.out.println(String.format("Please input grade of student #%d: ", i12 + 1));
                arr_grades[i12] = s.nextInt();
            }

            int sum_of_class = 0;
            for (int i13 = 0; i13 < arr_grades.length; i13++) {
                sum_of_class += arr_grades[i13];
            }
            float avg_of_class = sum_of_class / arr_grades.length;
            System.out.println(String.format("The average of the class is: %g", avg_of_class));

            sum_of_avg += avg_of_class;
            total_avg = sum_of_avg / classes.length;
        }
        System.out.println(String.format("The average of all classes is: %g", total_avg));

    }
}
