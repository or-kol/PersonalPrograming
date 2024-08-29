package com.company;

import java.util.Comparator;

public class CompareBySizeAndNumberOfPeople implements Comparator<Continent> {

    @Override
    public int compare(Continent o1, Continent o2) {
        if (Double.compare(o1.getM_size(), o2.getM_size()) == 0) {
            return o1.getM_population() - o2.getM_population();
        }
        return Double.compare(o1.getM_size(), o2.getM_size());
    }
}
