package com.company;

public class House {
    public final String address;
    public final float sqrMeters;
    public String owner;

    public House(String address, float sqrMeters, String owner) {
        this.address = address;
        this.sqrMeters = sqrMeters;
        this.owner = owner;
    }

    public House(String address, float sqrMeters) {
        this.address = address;
        this.sqrMeters = sqrMeters;
    }
}
