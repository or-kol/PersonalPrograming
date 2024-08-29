package com.company;

import lombok.ToString;

@ToString

public class Store {

    public String name;
    public final String address;
    private String m_owner_name;

    public Store(String name, String address, String m_owner_name) {
        this.name = name;
        this.address = address;
        this.m_owner_name = m_owner_name;
    }
}
