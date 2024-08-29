package com.company;

import java.util.Comparator;

public class CarSortBySeats implements Comparator<Car> {
    @Override
    public int compare(Car o1, Car o2) {
        return o1.getM_seats() - o2.getM_seats();
    }
}
