package com.company;

public class TV extends ElectricDevice{

    protected float m_screen_size;

    public TV(float m_screen_size) {
        super(false);
        this.m_screen_size = m_screen_size;
    }


    @Override
    public void useDevice() {
        System.out.println("Watching TV");
    }

    @Override
    public void fixDevice() {
        if (m_is_faulty == true) {
            System.out.println("Fixing TV");
            m_is_faulty = false;
        }
        else {
            System.out.println("This TV is working properly");
        }
    }
}
