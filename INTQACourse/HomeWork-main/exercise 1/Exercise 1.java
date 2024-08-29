package com.company;

import java.util.Random;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        Random r = new Random();


        //Q4
        int var1 = 5;
        int var2 = 20 + 12;
        float var3 = 7.5F;


        //Q5
        int a = 3;
        int b = 4;
        int sum = a + b;
        int multiply = a * b;


        //Q6
        String color = "blue";


        //Q7
        System.out.println("Please enter your name: ");
        String name = s.nextLine();
        System.out.println(String.format("Hello %s, welcome to Java", name));


        //Q8
        int year = 2020;
        year += 10;
        year -= 30;
        System.out.println(year);


        //Q9
        System.out.println("please enter 3 numbers: ");
        float num1 = s.nextFloat();
        float num2 = s.nextFloat();
        float num3 = s.nextFloat();
        System.out.println((num1 + num2 + num3) / 3);


        //Q10
        System.out.println("please input speed: ");
        int speed = s.nextInt();
        if (speed > 120) {
            System.out.println("Too fast!!");
        }
        else if (speed < 80) {
            System.out.println("Too slow!!");
        }
        else {
            System.out.println("Good driver!!");
        }


        //Q11
        System.out.println("input Tomer's age: ");
        int tomer = s.nextInt();
        System.out.println("input Danny's age: ");
        int danny = s.nextInt();
        if (tomer > danny) {
            System.out.println("Tomer is older!");
        }
        else {
            System.out.println("Danny is older!");
        }


        //Q12
        System.out.println("Please input two numbers: ");
        int c1 = s.nextInt();
        int c2 = s.nextInt();
        if (c1 == c2) {
            System.out.println("Numbers are equal");
        }
        else if (c1 < c2) {
            System.out.println(String.format("%d is smaller", c1));
        }
        else {
            System.out.println(String.format("%d is smaller", c2));
        }


        //Q13
        System.out.println("Please input three numbers: ");
        int d1 = s.nextInt();
        int d2 = s.nextInt();
        int d3 = s.nextInt();
        if (d1 < d2 && d1 > d3 || d1 > d2 && d1 < d3) {
            System.out.println(String.format("the middle number is %d", d1));
        }
        else if (d2 < d1 && d2 > d3 || d2 > d1 && d2 < d3) {
            System.out.println(String.format("the middle number is %d", d2));
        }
        else {
            System.out.println(String.format("the middle number is %d", d3));
        }


        //Q14
        System.out.println("Please input two numbers: ");
        int e1 = s.nextInt();
        int e2 = s.nextInt();
        if (e1 < e2) {
            System.out.println(String.format("%d, %d", e1, e2));
        }
        else {
            System.out.println(String.format("%d, %d", e2, e1));
        }


        //Q15
        for (int index = 0; index <= 10; index++) {
            System.out.println(index);
        }


        //Q16
        for (int index2 = 1; index2 <= 50; index2 += 2) {
            System.out.println(index2);
        }


        //Q17
        int f;

        do {
            f = r.nextInt(20) + 10;
            System.out.println(f);
        }
        while (f != 15);


        //Q18
        System.out.println("Please input a number: ");
        int g = s.nextInt();
        switch (g) {
            case 1:
                System.out.println("One");
                break;
            case 2:
                System.out.println("Two");
                break;
            case 3:
                System.out.println("Three");
                break;
            default:
                System.out.println("Unknown number");
                break;
        }


        //Q19


        int sum2 = 0;

        while (true) {
            System.out.println("please input number: ");
            int h = s.nextInt();
            if (h == 0) {
                break;
            }
            sum2 += h;
        }
        System.out.println(String.format("The sum is %d", sum2));


        //Q20
        System.out.println("please input three digits number: ");
        int i = s.nextInt();
        while (i < 100 || i > 999) {
            System.out.println("the number you entered contain more or less than three digits. please input three digits number: ");
            i = s.nextInt();
        }
        switch (i/100) {
            case 1:
                System.out.println(1);
                break;
            case 2:
                System.out.println(2);
                break;
            case 3:
                System.out.println(3);
                break;
            case 4:
                System.out.println(4);
                break;
            case 5:
                System.out.println(5);
                break;
            case 6:
                System.out.println(6);
                break;
            case 7:
                System.out.println(7);
                break;
            case 8:
                System.out.println(8);
                break;
            case 9:
                System.out.println(9);
                break;
        }


        //Q21
        float j;
        float sum3 = 0;
        float counter = 0;

        do {
            System.out.println("please input grade: ");
            j = s.nextFloat();
            if (j < -1 || j > 100) {
                continue;
            }
            sum3 += j;
            counter++;
        }
        while (j != -1);

        float average = (++sum3) / (--counter);
        System.out.println(String.format("the average is: %g", average));


        //Q22
        System.out.println("please input a number: ");
        int index3 = s.nextInt();
        int multi = index3;

        while (multi > 1){
            index3 *= multi - 1;
            multi--;
        }

        System.out.println(index3);


       //Q23
      System.out.println("please input a number: ");
      int k = s.nextInt();
      int highest = k;

      while (k != -1){
          System.out.println("please input a number: ");
          k = s.nextInt();
          if (k > highest && k !=  -1) {
              highest = k;
          }
      }

        System.out.println(String.format("The highest input is %d", highest));


        //Q24
        System.out.println("please input a number: ");

        for (int no_lines = s.nextInt(); no_lines > 0; no_lines--) {
            System.out.print("-");
        }


        //Q25
        int temp;
        int count_in = 0;
        int count_out = 0;

        do {
            System.out.println("please input temperature: ");
            temp = s.nextInt();
            if (temp <= 37) {
                System.out.println("Welcome!!");
                count_in++;
            }
            else {
                System.out.println("Sorry, can not enter!!");
                count_out++;
            }
        }
        while (temp != -1);

        System.out.println(String.format("%d customers entered and %d customers could not enter", --count_in, count_out));


        //Q26
        int loto1 = r.nextInt(100) + 1;
        int loto2 = r.nextInt(100) + 1;
        int loto3 = r.nextInt(100) + 1;

        System.out.println("please input 3 guesses:");
        int guess1 = s.nextInt();
        int guess2 = s.nextInt();
        int guess3 = s.nextInt();

        if ((loto1 == guess1 || loto1 == guess2 || loto1 == guess3) && (loto2 == guess1 || loto2 == guess2 || loto2 == guess3) && (loto3 == guess1 || loto3 == guess2 || loto3 == guess3)) {
            System.out.println("You won 1,000,000 NIS!!");
        }
        else if ((loto1 == guess1 || loto1 == guess2 || loto1 == guess3) && (loto2 == guess1 || loto2 == guess2 || loto2 == guess3)) {
            System.out.println("You won 100,000 NIS!!");
        }
        else if ((loto1 == guess1 || loto1 == guess2 || loto1 == guess3) && (loto3 == guess1 || loto3 == guess2 || loto3 == guess3)) {
            System.out.println("You won 100,000 NIS!!");
        }
        else if ((loto2 == guess1 || loto2 == guess2 || loto2 == guess3) && (loto3 == guess1 || loto3 == guess2 || loto3 == guess3)) {
            System.out.println("You won 100,000 NIS!!");
        }
        else if (loto1 == guess1 || loto1 == guess2 || loto1 == guess3 || loto2 == guess1 || loto2 == guess2 || loto2 == guess3 || loto3 == guess1 || loto3 == guess2 || loto3 == guess3) {
            System.out.println("You won 100 NIS!!");
        }
        else {
            System.out.println("You lost");
        }


        //Q27
        System.out.println("plesae input hourly wage: ");
        int hourly_wage = s.nextInt();

        System.out.println("please input amount of hours: ");
        int hours = s.nextInt();

        int salary = hourly_wage * hours;
        double net_sal = 0;

        if (salary < 1000) {
            net_sal = salary * 0.98;
        }
        else if (salary >= 1000 && salary <= 5000) {
            net_sal = salary * 0.9;
        }
        else if (salary > 5000) {
            net_sal = salary * 0.8;
        }

        System.out.println(String.format("Final salary is %g", net_sal));


        //Q28
        int prs, player;

        do {
            prs = r.nextInt(3) + 1;

            System.out.println("please type 1 for Rock, 2 for Paper or 3 for Scissors: (input 0 to exit)");
            player = s.nextInt();

            if (player == 0) {
                break;
            }

            if (player < 1 || player > 3) {
                System.out.println("the number you entered is not in scope!");
                continue;
            }

            if (player == 1 && prs == 2 || player == 2 && prs == 3 || player == 3 && prs == 1) {
                System.out.println("computer wins");
            }
            else if (player == 1 && prs ==3 || player == 2 && prs == 1 || player == 3 && prs ==2){
                System.out.println("player wins");
            }
            else {
                System.out.println("Tie");
            }
        }
        while (true);













    }
}
