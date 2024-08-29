package com.company;

import lombok.Getter;
import lombok.Setter;

public class Labrador extends Dog{
    private @Getter @Setter int intelligenceQuantity;

    public void bringSlippers() {
        System.out.println(String.format("%s, bring the slippers", getM_name()));
    }
}
