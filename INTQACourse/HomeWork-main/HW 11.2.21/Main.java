package com.company;

public class Main {

    public static void main(String[] args) {

        Animal ani = new Animal();
        Cat c = new Cat();
        Dog d = new Dog();
        Labrador l = new Labrador();
        SiamiCat s = new SiamiCat();

        Animal[] animals = {new Animal(), new Cat(), new Dog(), new SiamiCat(), new Labrador()};

        for (int i = 0; i < animals.length; i++) {
            animals[i].goToVet();
        }
        
        printSize(ani);
        printSize(c);
        printSize(d);
        printSize(l);
        printSize(s);

        dogGourdTheHouse(d);
        dogGourdTheHouse(l);
    }

    public static void printSize(Animal a) {
        System.out.println(a.getM_size());
    }

    public static void dogGourdTheHouse(Dog d) {
        d.gourdHouse();
    }
}
