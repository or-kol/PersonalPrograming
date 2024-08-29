package com.company;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {

        ArrayList<Integer> num = new ArrayList<>();
        num.add(3);
        num.add(5);
        num.add(3);
        num.add(3);
        num.add(8);
        num.add(12);
        num.add(12);
        num.add(15);
        num.add(3);

        getNumLastPlace(num, 12);
        getAllNumPlaces(num, 3);
    }

    public static void getNumLastPlace(ArrayList array, int x) {
        int count = 0;
        for (int i = array.size() - 1; i >= 0; i--) {
            if (array.get(i).equals(x)) {
                System.out.println(String.format("the last place the number %d appears in is: %d", x, i));
                count++;
                break;
            }
        }
        if (count == 0) {
            System.out.println(String.format("the number %d does not exist in the list", x));
        }
    }


    public static void getAllNumPlaces(ArrayList array, int x) {
        ArrayList<Integer> numPlaces = new ArrayList<>();
        for (int i = 0; i < array.size(); i++) {
            if (array.get(i).equals(x)) {
                numPlaces.add(i);
            }
        }

        for (int i = 0; i < numPlaces.size(); i++) {
            System.out.println(String.format("The number %d appears int place: %d", x, numPlaces.get(i)));
        }
    }
}
