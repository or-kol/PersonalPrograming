package com.company;

public abstract class ElectricDevice {

    protected float m_voltage;
    protected boolean m_works_on_batteries;
    protected boolean m_is_faulty;

    public ElectricDevice(boolean m_works_on_batteries) {
        this.m_works_on_batteries = m_works_on_batteries;
        this.m_is_faulty = false;
    }

    public void turnOn() {
        System.out.println("Turning on device");
    }

    public final void insertNewBatteries() {
        if (m_works_on_batteries == true) {
            System.out.println("Inserting new batteries to the device");
        }
        else {
            System.out.println("This device doesn't use batteries");
        }
    }

    public abstract void useDevice();

    public abstract void fixDevice();
}
