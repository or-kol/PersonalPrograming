package com.company;

import java.util.Random;

public class Main {

    public static void main(String[] args) {

        Random r = new Random();

        // 1. write for-loop which prints the numbers from 100 to 1000 in 100 steps: 100, 200, 300, .... 1000

        for (int index8 = 100; index8 <= 1000; index8 += 100) {
            System.out.println(index8);
        }


        // 2. write for-loop which prints numbers from 5 to -10 (minus)

        for (int index9 = 5; index9 >= -10; index9--) {
            System.out.println(index9);
        }


        // 3. *etar: use for-loop to print the power of 2: 1, 2, 4, 8, 16, 32, 64, ... 2048

        for (int index10 = 2; index10 <= 2048; index10 *= 2) {
            System.out.println(index10);
        }


        // 4. generate a random number from 1-3
        // use switch-case to print the number in hebrew.
        // for exmaple if 1 was generated -> print "ehad", 2 -> print "shtaim" , 3 -> print "shalosh"

        int random = r.nextInt(3) + 1;

        switch (random) {
            case 1:
                System.out.println("Ehad");
                break;
            case 2:
                System.out.println("Shtaim");
                break;
            case 3:
                System.out.println("Shalosh");
                break;
        }

    }
}
