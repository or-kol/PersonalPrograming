package com.company;

import lombok.AllArgsConstructor;
import lombok.ToString;

@AllArgsConstructor
@ToString

public class Weather {

    public float temperature;
    public float humidity;
    public boolean cloudy;
    public float chanceOfRain;

    public void changeChanceOfRain(float a) {
        if (a >= 0 && a <= 100) {
            chanceOfRain = a;
        }
        else {
            System.out.println("chance must be between 0-100!");
        }
    }

    public void printTempFahrenheit () {
        System.out.println(String.format("the temperature is %f celsius and %f fahrenheit", temperature, temperature * 1.8 + 32));
    }
}
