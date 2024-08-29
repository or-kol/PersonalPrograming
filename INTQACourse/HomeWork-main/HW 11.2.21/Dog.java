package com.company;

import lombok.Getter;
import lombok.Setter;

public class Dog extends Animal{

    private @Getter @Setter int barkLength;


    public void gourdHouse() {
        System.out.println(String.format("%s Gouard the house", getM_name()));
    }
}
