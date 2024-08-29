package com.company;

public class Car extends Vehicle{

    protected int m_numberOfDoors;

    public Car(int m_numberOfWheels, String m_model, int m_numberOfDoors) {
        super(m_numberOfWheels, m_model);
        this.m_numberOfDoors = m_numberOfDoors;
    }

    @Override
    public int getMaxNumOfPassengers() {
        return m_numberOfWheels + 1;
    }

    @Override
    public int getMaxSpeed() {
        return m_numberOfDoors * m_numberOfWheels * 10;
    }
}
