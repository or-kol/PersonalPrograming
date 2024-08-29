package com.forest;

import java.time.LocalDate;

public class Aircraft {

    private final String m_manufacturer;
    private float m_max_speed;
    private float m_max_altitude;
    private final LocalDate m_production_date;


    public String getM_manufacturer() {
        return m_manufacturer;
    }

    public float getM_max_speed() {
        return m_max_speed;
    }

    public float getM_max_altitude() {
        return m_max_altitude;
    }

    public LocalDate getM_production_date() {
        return m_production_date;
    }


    public Aircraft(String m_manufacturer, float m_max_speed, float m_max_altitude) {
        this.m_manufacturer = m_manufacturer;
        this.m_max_speed = m_max_speed;
        this.m_max_altitude = m_max_altitude;
        this.m_production_date = LocalDate.now();
    }
}
