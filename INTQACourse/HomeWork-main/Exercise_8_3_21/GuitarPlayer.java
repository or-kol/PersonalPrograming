package com.company;

public class GuitarPlayer extends Player{


    @Override
    public void play() {
        System.out.println("Playing hotel california");
    }

    @Override
    public void compose() {
        System.out.println("Compose guitar melody");
    }

    public void rockAndRoll() {
        System.out.println("Let the show begin");
    }
}
