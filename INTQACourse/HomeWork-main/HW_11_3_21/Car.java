package com.company;

import java.time.LocalDateTime;

public class Car implements Comparable<Car>{

    protected String m_id;
    protected String m_brand;
    protected String m_model;
    protected LocalDateTime m_creation_date;
    protected String m_color;
    protected int m_seats;

    public Car(String m_id, String m_brand, String m_model, LocalDateTime m_creation_date, String m_color, int m_seats) {
        this.m_id = m_id;
        this.m_brand = m_brand;
        this.m_model = m_model;
        this.m_creation_date = m_creation_date;
        this.m_color = m_color;
        this.m_seats = m_seats;
    }

    public String getM_brand() {
        return m_brand;
    }

    public int getM_seats() {
        return m_seats;
    }

    public LocalDateTime getM_creation_date() {
        return m_creation_date;
    }

    public String getM_color() {
        return m_color;
    }

    public String getM_id() {
        return m_id;
    }

    public String getM_model() {
        return m_model;
    }

    @Override
    public String toString() {
        return "Car{" +
                "m_id='" + m_id + '\'' +
                ", m_brand='" + m_brand + '\'' +
                ", m_model='" + m_model + '\'' +
                ", m_creation_date=" + m_creation_date +
                ", m_color='" + m_color + '\'' +
                ", m_seats=" + m_seats +
                '}';
    }

    @Override
    public int compareTo(Car o) {
        return this.m_id.compareTo(o.m_id);
    }
}
