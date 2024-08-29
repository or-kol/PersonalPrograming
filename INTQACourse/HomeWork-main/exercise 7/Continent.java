package com.company;

public class Continent implements Comparable<Continent>{

    private String m_name;
    private double m_size;
    private int m_population;

    public Continent(String m_name, double m_size, int m_population) {
        this.m_name = m_name;
        this.m_size = m_size;
        this.m_population = m_population;
    }

    @Override
    public String toString() {
        return "Continent{" +
                "m_name='" + m_name + '\'' +
                ", m_size=" + m_size +
                ", m_population=" + m_population +
                '}';
    }

    public String getM_name() {
        return m_name;
    }

    public double getM_size() {
        return m_size;
    }

    public int getM_population() {
        return m_population;
    }

    @Override
    public int compareTo(Continent o) {
        return this.m_name.compareTo(o.m_name);
    }

}
