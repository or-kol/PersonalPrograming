package com.company;

public class Item {

    protected Integer m_key;
    protected Person m_data;

    public Item(Integer m_key, Person m_data) {
        this.m_key = m_key;
        this.m_data = m_data;
    }

    public Integer getM_key() {
        return m_key;
    }

    public Person getM_data() {
        return m_data;
    }
}
