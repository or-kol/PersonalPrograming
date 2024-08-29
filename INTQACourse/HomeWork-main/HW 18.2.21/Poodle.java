package com.company;

public class Poodle extends Dog{

    protected String m_numberOfPonyTails;

    public Poodle(String m_name, String m_favoriteDogFood, String m_numberOfPonyTails) {
        super(m_name, m_favoriteDogFood);
        this.m_numberOfPonyTails = m_numberOfPonyTails;
    }

    @Override
    public void bark() {
        System.out.println("Woof Woof!!!");
    }

    @Override
    public String toString() {
        return super.toString() +
                "Poodle{" +
                "m_numberOfPonyTails='" + m_numberOfPonyTails + '\'' +
                '}';
    }
}
