package com.company;

public class Horse extends Animal{

    boolean m_racingHorse;

    public Horse(String m_name, boolean m_racingHorse) {
        super(m_name);
        this.m_racingHorse = m_racingHorse;
    }

    public void neigh() {
        System.out.println("Neigh!!");
    }

    @Override
    public String toString() {
        return super.toString() +
                "Horse{" +
                "m_racingHorse=" + m_racingHorse +
                '}';
    }
}
