package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args)
    {

        Scanner s = new Scanner(System.in);
    
        // 1. print "Please enter temperature"
        System.out.println("Please enter temperature: ");

        // 2. input from user a float number into variable called "temperature" (nextFloat)
        float temperature = s.nextFloat();

        // 3. if temperature is higher than 36.5 print "Hot"
        if (temperature > 36.5) {
            System.out.println("Hot");
        }

        // 4. if temperature is lower than 36.5 print "Cold"
        if (temperature < 36.5) {
            System.out.println("cold");
        }

        // 5. print "please enter your age"
        System.out.println("Please enter age: ");

        // 6. input from user an int number into variable called "my_age" (nextInt)
        int my_age = s.nextInt();

        // 7. if age is bigger than 18 print "Grown up"
        if (my_age > 18) {
            System.out.println("Grow up");
        }

        // 8. if age is smaller than 13 print "Child"
        if (my_age < 13) {
            System.out.println("Child");
        }

        // 9. print "Please enter number for a"
        System.out.println("Please enter number for a: ");

        // 10. input from user a double number into variable called "a" (nextDouble)
        double a = s.nextDouble();

        // 11. print "Please enter number for b"
        System.out.println("Please enter number for b: ");

        // 12. input from user a double number into variable called "b" (nextDouble)
        double b = s.nextDouble();

        // 13. if a > b
        // print "a is bigger"
        // print a
        if (a > b) {
            System.out.println("a is bigger");
            System.out.println(a);
        }
        // 14. if a < b
        // print "b is bigger"
        // print b
        if (a < b) {
            System.out.println("b is bigger");
            System.out.println(b);
        }
    }
}
