package com.company;

public class Dog extends Animal{

    protected String m_favoriteDogFood;

    public Dog(String m_name, String m_favoriteDogFood) {
        super(m_name);
        this.m_favoriteDogFood = m_favoriteDogFood;
    }

    public void bark() {
        System.out.println("Woof!!");
    }

    @Override
    public String toString() {
        return super.toString() +
                "Dog{" +
                "m_favoriteDogFood='" + m_favoriteDogFood + '\'' +
                '}';
    }
}
