package com.company;

public class Motorcycle extends Vehicle{

    protected float m_handBreakSize;

    public Motorcycle(int m_numberOfWheels, String m_model, float m_handBreakSize) {
        super(m_numberOfWheels, m_model);
        this.m_handBreakSize = m_handBreakSize;
    }

    @Override
    public int getMaxNumOfPassengers() {
        return m_numberOfWheels;
    }

    @Override
    public int getMaxSpeed() {
        return m_numberOfWheels * 100;
    }
}
