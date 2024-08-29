package com.company;

import java.util.Comparator;

public class ContinentSortByPopulationReverse implements Comparator<Continent> {
    @Override
    public int compare(Continent o1, Continent o2) {
        return o2.getM_population() - o1.getM_population();
    }
}
