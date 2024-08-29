package com.company;

import lombok.ToString;

@ToString

public class Surgeon extends Doctor{

    private String m_department;
    private int m_yearsOfExperience;


    public String getM_department() {
        return m_department;
    }

    public void setM_department(String m_department) {
        this.m_department = m_department;
    }

    public int getM_yearsOfExperience() {
        return m_yearsOfExperience;
    }

    public void setM_yearsOfExperience(int m_yearsOfExperience) {
        this.m_yearsOfExperience = m_yearsOfExperience;
    }


    public Surgeon(int m_doctor_id, String m_doctor_name, String m_hospital, String m_department, int m_yearsOfExperience) {
        super(m_doctor_id, m_doctor_name, m_hospital);
        this.m_department = m_department;
        this.m_yearsOfExperience = m_yearsOfExperience;
    }
}
