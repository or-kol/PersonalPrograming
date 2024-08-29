package com.company;

import lombok.ToString;

@ToString

public class Guitar {

    private final String m_brand;
    private final boolean m_is_electric;
    private final int m_number_of_strings;
    private float m_price;
    private boolean m_is_tuned;

    public String getM_brand() {
        return m_brand;
    }

    public boolean getM_is_electric() {
        return m_is_electric;
    }

    public int getM_number_of_strings() {
        return m_number_of_strings;
    }

    public float getM_price() {
        return m_price;
    }

    public void setM_price(float m_price) {
        this.m_price = m_price;
    }

    public boolean getM_is_tuned() {
        return m_is_tuned;
    }


    public Guitar(String m_brand, boolean m_is_electric, int m_number_of_strings, float m_price, boolean m_is_tuned) {
        this.m_brand = m_brand;
        this.m_is_electric = m_is_electric;
        this.m_number_of_strings = m_number_of_strings;
        this.m_price = m_price;
        this.m_is_tuned = m_is_tuned;
    }

    public Guitar(String m_brand, boolean m_is_electric) {
        this(m_brand, m_is_electric, 6, 50f, false);
    }

    public Guitar(String m_brand) {
        this(m_brand, false, 6, 50f, false);
    }


    public void tuneGuitar() {
        System.out.println("Guitar is tuned");
        m_is_tuned = true;
    }
}
