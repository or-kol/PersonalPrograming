package com.company;

public abstract class Ball implements Tossable{

    private String brandName;


    public Ball(String brandName) {
        this.brandName = brandName;
    }


    public String getBardName() {
        return brandName;
    }

    public abstract void bounce();
}
