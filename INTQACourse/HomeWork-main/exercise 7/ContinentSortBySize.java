package com.company;

import java.util.Comparator;

public class ContinentSortBySize implements Comparator<Continent> {
    @Override
    public int compare(Continent o1, Continent o2) {
        return Double.compare(o1.getM_size(), o2.getM_size());
    }
}
