package com.company;

import lombok.AllArgsConstructor;
import lombok.ToString;

@AllArgsConstructor
@ToString

public class Meal {

    public String name;
    public boolean vegan;
    public float price;

    /*
    public Meal(String name, boolean vegan, float price) {
        this.name = name;
        this.vegan = vegan;
        this.price = price;
    }
     */
}
