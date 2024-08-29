package com.company;

import lombok.ToString;

@ToString

public class Doctor {

    private final int m_doctor_id;
    private String m_doctor_name;
    private String m_hospital;


    public int getM_doctor_id() {
        return m_doctor_id;
    }

    public String getM_doctor_name() {
        return m_doctor_name;
    }

    public String getM_hospital() {
        return m_hospital;
    }

    public void setM_hospital(String m_hospital) {
        this.m_hospital = m_hospital;
    }


    public Doctor(int m_doctor_id, String m_doctor_name, String m_hospital) {
        this.m_doctor_id = m_doctor_id;
        this.m_doctor_name = m_doctor_name;
        this.m_hospital = m_hospital;
    }
}
