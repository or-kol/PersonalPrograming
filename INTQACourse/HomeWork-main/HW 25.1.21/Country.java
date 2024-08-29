package com.company;

import lombok.AllArgsConstructor;
import lombok.ToString;

@AllArgsConstructor
@ToString
public class Country {

    //Create a class called Country
    //Fields:
    //String name, double size, int numberOfCitizens, String continent
    //Ctor:
    //with all parameters
    //Functions:
    //printCountrySize()
    //printSizePerCitizen()
    //ToString()
    //
    //Now add lombok:
    //Ctor with all args
    //ToString
    public String name;
    public double size;
    public  int numberOfCitizens;
    public String continent;
/*
    public Country(String name, double size, int numberOfCitizens, String continent) {
        this.name = name;
        this.size = size;
        this.numberOfCitizens = numberOfCitizens;
        this.continent = continent;
    }
*/
    public void printCountrySize () {
        System.out.println(String.format("%s's area is %f", name, size));
    }

    public void printSizePerCitizens () {
        System.out.println(String.format("%s has %f people per square kilometers", name, numberOfCitizens / size));
    }
/*
    @Override
    public String toString() {
        return "Country{" +
                "name='" + name + '\'' +
                ", size=" + size +
                ", numberOfCitizens=" + numberOfCitizens +
                ", continent='" + continent + '\'' +
                '}';
    }

 */
}
