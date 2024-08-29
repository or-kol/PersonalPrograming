package com.company;

import java.util.Comparator;

public class CarSortByBrandCreation implements Comparator<Car> {

    @Override
    public int compare(Car o1, Car o2) {
        return o1.getM_creation_date().compareTo(o2.getM_creation_date());
    }
}
