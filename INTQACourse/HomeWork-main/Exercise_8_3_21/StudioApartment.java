package com.company;

public class StudioApartment extends Apartment{

    protected float m_number_of_rooms;

    @Override
    public String toString() {
        return super.toString() +
                "StudioApartment{" +
                "m_number_of_rooms=" + m_number_of_rooms +
                '}';
    }
}
