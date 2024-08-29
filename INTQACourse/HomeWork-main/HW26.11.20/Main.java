package com.company;

import javax.print.DocFlavor;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        String id = "200701100";
        String full_name = "Or Kol";
        String address = "Magshimim";
        String details = (id + " " + full_name + " " + address);
        System.out.println(details);

        System.out.println("First Name:");
        Scanner first_name_scanner = new Scanner(System.in);
        String first_name = first_name_scanner.nextLine();

        System.out.println("Last Name:");
        Scanner last_name_scanner = new Scanner(System.in);
        String last_name = last_name_scanner.nextLine();

        System.out.println(first_name + " " + last_name);
    }
}
