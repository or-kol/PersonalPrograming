package com.company;

import java.util.Scanner;

public class Main301120
{

    public static void main(String[] args)
    {
        System.out.println("Enter your name:");
        Scanner n = new Scanner(System.in);
        String my_name = n.nextLine();

        int my_savings = 0;
        my_savings += 10000;
        my_savings *= 2;
        my_savings += 30000;
        my_savings++;
        my_savings /= 2;

        System.out.println(my_name + " " + "has savings of " + my_savings);
        
        //my_savings = 25000
        //my_savings after changing the original value = 125000
    }
}
