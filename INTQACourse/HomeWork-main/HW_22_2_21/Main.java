package com.company;

public class Main {

    public static void main(String[] args) {

        Animal[] animals = {new Dog("abc"), new Cat("xyz")};

        for (int i = 0; i < animals.length; i++) {
            makeSound(animals[i]);
        }


    }


    public static void makeSound(Animal animal) {
        if (animal instanceof Dog) {
            ((Dog) animal).bark();
        }
        else if (animal instanceof Cat) {
            ((Cat) animal).miauu();
        }
    }

}
