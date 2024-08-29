package com.company;

public class Baseball extends Ball{

    public Baseball(String brandName) {
        super(brandName);
    }

    @Override
    public void toss() {
        System.out.println("Toss the baseball");
    }

    @Override
    public void bounce() {
        System.out.println("Bounce the baseball");;
    }
}
