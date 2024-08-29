package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        // Home work
        // 1. write all numbers from -1000 to +1000 using do-while loop

        int x = -1000;

        do {
            System.out.println(x);
            x++;
        }
        while (x <= 1000);



        // 2. read oreh,rohav,hekef from user until the hekef was 2*oreh+2*rohav using do-while loop
        // for exmaple:
        // oreh=3, rohav=4, hekef=12 is wrong, since 3*2 + 4*2 = 14... so the user should input the numbers again
        // oreh=1, rohav=5, hekef=12 is correct since 1*2 + 5*2 = 12... so the loop should end after this input

        Float oreh, rohav, hekef;

        do {
            System.out.println("please input oreh, rohav and hekef: ");
            oreh = s.nextFloat();
            rohav = s.nextFloat();
            hekef = s.nextFloat();
        }
        while (!(2 * oreh + 2 * rohav == hekef));

        System.out.println(String.format("hekef: %e + %e = %e", 2*oreh, 2*rohav, hekef));



        // 3. now solve targil 1,2 to using while(true)+break loop

        while (true) {
            System.out.println(x);
            x++;
            if (x > 1000) {
                break;
            }
        }



        System.out.println("please input oreh, rohav and hekef: ");
        oreh = s.nextFloat();
        rohav = s.nextFloat();
        hekef = s.nextFloat();

        while (true) {
            if (2 * oreh + 2 * rohav == hekef) {
                break;
            }
            System.out.println("please input oreh, rohav and hekef: ");
            oreh = s.nextFloat();
            rohav = s.nextFloat();
            hekef = s.nextFloat();
        }

        System.out.println(String.format("hekef: %e + %e = %e", 2 * oreh, 2 * rohav, hekef));




        // 4. read temperature from user (float)
        // if temperature < 35 print "out-of-range" + break
        // if temperature > 42 print "out-of-range" + break
        // if temperature > 37.5 and temperature <= 42 print "sick"
        // if temperature > 35 and temperature <= 37.5 print "healthy"
        // use while (true) + break

        System.out.println("please input temperature: ");
        float temp = s.nextFloat();

        while (true) {
            if (temp < 35 || temp > 42) {
                System.out.println("out of range");
                break;
            }
            if (temp > 37.5) {
                System.out.println("sick");
                break;
            }
            if (temp <= 37.5) {
                System.out.println("healthy");
                break;
            }
        }

    }
}
