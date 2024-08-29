package com.company;

import java.util.Comparator;

public class CarSortByColor implements Comparator<Car> {
    @Override
    public int compare(Car o1, Car o2) {
        return o1.getM_color().compareTo(o2.getM_color());
    }
}
