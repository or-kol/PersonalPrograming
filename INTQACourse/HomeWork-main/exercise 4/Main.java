package com.company;

public class Main {

    public static void main(String[] args) {

        // 


        //7
        printDog();


        //15
        Memory.add(15);
        Memory.add(22.2f);
        Memory.add("abc");

    }


    //17
    public static void bankAccounts() {
        BankAccount[] accounts = {new BankAccount("abc", 180f, 50),
                new BankAccount("def", -70000f,20),
                new BankAccount("ghj", 100000, 100)};

        accounts[0].checkBalance();
        accounts[1].checkBalance();
        accounts[2].checkBalance();

        if (accounts[0].creditScore > accounts[1].creditScore && accounts[0].creditScore > accounts[2].creditScore) {
            accounts[0].deposit(1000);
        }
        else if (accounts[1].creditScore > accounts[2].creditScore) {
            accounts[1].deposit(1000);
        }
        else {
            accounts[2].deposit(1000);
        }

    }


    //12
    public static void createHouses() {
        House h1 = new House("assdf", 25.555f, "arty");
        House h2 = new House("oiuyt", 125.977f);
    }


    //9
    public static void createMeals() {
        Meal meal1 = new Meal("fgh", false, 25.4f);
        Meal meal2 = new Meal("rty", true, 30.99f);
    }


    //7
    public static void printDog () {
        Dog dog2 = new Dog();
        dog2.name = "xyz";
        dog2.age = 7;
        dog2.breed = "Poodle";

        System.out.println(dog2);
    }


    //4
    public static void creatDog() {
        Dog dog1 = new Dog();
        dog1.name = "abc";
        dog1.age = 11;
        dog1.breed = "Bulldog";
    }



}
