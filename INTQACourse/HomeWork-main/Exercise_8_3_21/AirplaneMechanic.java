package com.company;

public class AirplaneMechanic extends Mechanic{

    protected int rank;

    @Override
    public void repair() {
        System.out.println("Repairing airplane");
    }

    public void checkEngine() {
        System.out.println("Checking the engine");
    }
}
