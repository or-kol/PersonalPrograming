package com.company;

public abstract class Mechanic {

    protected String m_name;
    protected int m_years_of_experience;


    public abstract void repair();

    public void useScrewdriver() {
        System.out.println("Using screwdriver to open this screw");
    }
}
