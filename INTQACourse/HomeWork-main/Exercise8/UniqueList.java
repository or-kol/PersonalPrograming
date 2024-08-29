package com.company;

import java.util.Set;

public class UniqueList {

    Set<Integer> numbers_list;

    public boolean add(int x) {
        numbers_list.add(x);
        if(x > 0) {
            return true;
        }
        else if (x < 0) {
            return false;
        }

        System.out.println("Exception"); //we didn't learn Exceptions yet!!!!!

        return false;
    }

}
