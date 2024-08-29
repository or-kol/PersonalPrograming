package com.company;

import lombok.Getter;
import lombok.Setter;

public class Cat extends Animal {

    private @Getter @Setter String favoriteMilkName;


    public void cuddle() {
        System.out.println(String.format("%s likes to cuddle", getM_name()));
    }
}