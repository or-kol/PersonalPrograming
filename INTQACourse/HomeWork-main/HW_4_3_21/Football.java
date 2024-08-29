package com.company;

public class Football extends Ball{

    public Football(String brandName) {
        super(brandName);
    }

    @Override
    public void bounce() {
        System.out.println("Bounce the football");
    }

    @Override
    public void toss() {
        System.out.println("Toss the football");
    }
}
