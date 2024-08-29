package com.company;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Collections;

public class Main {

    public static void main(String[] args) {

        ArrayList<Car> cars = new ArrayList<>();
        cars.add(new Car("11-222-33", "Mitsubishi", "ASX",
                LocalDateTime.of(2001, 12, 7, 0, 0, 0), "Black", 5));
        cars.add(new Car("23-567-44", "Hyundai", "Accent",
                LocalDateTime.of(2010, 3, 15, 0, 0, 0), "Silver", 6));
        cars.add(new Car("59-357-86", "Hyundai", "I20",
                LocalDateTime.of(2013, 8, 9, 0, 0, 0), "Silver", 5));
        cars.add(new Car("55-588-37", "Daihatsu", "Sirrion",
                LocalDateTime.of(2019, 4, 22, 0, 0, 0), "Green", 7));
        cars.add(new Car("74-829-49", "Skoda", "Octavia",
                LocalDateTime.of(2010, 3, 30, 0, 0, 0), "White", 4));
        cars.add(new Car("16-257-94", "Skoda", "Fabia",
                LocalDateTime.of(2010, 7, 15, 0, 0, 0), "Blue", 5));
        cars.add(new Car("96-468-84", "Kia", "Rio",
                LocalDateTime.of(2010, 8, 15, 0, 0, 0), "Yellow", 3));


        Collections.sort(cars);

        for (int i = 0; i < cars.size(); i++) {
            System.out.println(cars.get(i));
        }
        System.out.println();


        Collections.sort(cars, new CarSortByBrandAndModel());

        for (int i = 0; i < cars.size(); i++) {
            System.out.println(cars.get(i));
        }
        System.out.println();


        Collections.sort(cars, new CarSortByBrandCreation());

        for (int i = 0; i < cars.size(); i++) {
            System.out.println(cars.get(i));
        }
        System.out.println();


        Collections.sort(cars, new CarSortByColor());

        for (int i = 0; i < cars.size(); i++) {
            System.out.println(cars.get(i));
        }
        System.out.println();


        Collections.sort(cars, new CarSortBySeats());

        for (int i = 0; i < cars.size(); i++) {
            System.out.println(cars.get(i));
        }
    }
}
