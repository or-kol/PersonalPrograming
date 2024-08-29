package com.company;

import java.util.SplittableRandom;

public class Dog {
    //4
    public String name;
    public int age;
    public String breed;


    //5
    public void bark () {
        System.out.println(String.format("Woof Woof, %s", name));
    }


    //7
    @Override
    public String toString() {
        return "Dog{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", breed='" + breed + '\'' +
                '}';
    }
}
