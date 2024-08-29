package com.company;

import lombok.ToString;

@ToString

public class FamilyDoctor extends Doctor{

    private boolean m_is_occupied;
    private String m_clinic;


    public boolean getM_is_Occupied() {
        return m_is_occupied;
    }

    public void setM_is_occupied(boolean m_is_occupied) {
        this.m_is_occupied = m_is_occupied;
    }

    public String getM_clinic() {
        return m_clinic;
    }


    public FamilyDoctor(int m_doctor_id, String m_doctor_name, String m_hospital, boolean m_is_occupied, String m_clinic) {
        super(m_doctor_id, m_doctor_name, m_hospital);
        this.m_is_occupied = m_is_occupied;
        this.m_clinic = m_clinic;
    }


    public void acceptClient() {
        if (m_is_occupied = true) {
            System.out.println("The doctor is busy");
        }
        else {
            System.out.println("Welcome");
            m_is_occupied = true;
        }
    }

    public void finishAppointment() {
        m_is_occupied = false;
    }
}
