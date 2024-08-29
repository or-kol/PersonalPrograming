package com.company;

public class Animal {

    protected String m_name;

    public Animal(String m_name) {
        this.m_name = m_name;
    }

    @Override
    public String toString() {
        return "Animal{" +
                "m_name='" + m_name + '\'' +
                '}';
    }
}
