package com.company;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@ToString

public class MyClass {

    private @Getter @Setter String m_name;
    private String m_place;

    public String getPlace(String place) {
        return place;
    }

    public void setPlace(String place) {
        m_place = place;
    }
}
