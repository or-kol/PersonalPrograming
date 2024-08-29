package com.company;

import java.util.Comparator;

public class CarSortByBrandAndModel implements Comparator<Car> {
    @Override
    public int compare(Car o1, Car o2) {
        if (o1.getM_brand().compareTo(o2.getM_brand()) == 0) {
            return o1.getM_model().compareTo(o2.getM_model());
        }
        return o1.getM_brand().compareTo(o2.getM_brand());
    }
}
