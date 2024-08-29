package com.company;


public class Building {

    private int m_number_of_residents;
    private boolean m_is_building_clean;
    private boolean m_is_electricity_working;
    private float m_cashbox;

    public Building(int m_number_of_residents, boolean m_is_building_clean, boolean m_is_electricity_working, float m_cashbox) {
        this.m_number_of_residents = m_number_of_residents;
        this.m_is_building_clean = m_is_building_clean;
        this.m_is_electricity_working = m_is_electricity_working;
        this.m_cashbox = m_cashbox;
    }


    public int getM_number_of_residents() {
        return m_number_of_residents;
    }

    public float getM_cashbox() {
        return m_cashbox;
    }

    public boolean getM_is_building_clean() {
        return m_is_building_clean;
    }

    public boolean getM_is_electricity_working() {
        return m_is_electricity_working;
    }



    public boolean maintainBuilding() {
        if (m_is_building_clean == false) {
            boolean cleaner = callCleaner();
            if (cleaner == false) {
                return false;
            }
        }

        if (m_is_electricity_working == false) {
            boolean electrician = callElectrician();
            if (electrician == false) {
                return false;
            }
        }

        return true;
    }


    public boolean callCleaner() {
        if (m_cashbox < 100) {
            return false;
        }

        m_cashbox -= 100;
        m_is_building_clean = true;

        return true;
    }


    public boolean callElectrician() {
        if (m_cashbox < 300) {
            return false;
        }

        m_cashbox -= 300;
        m_is_electricity_working = true;

        return true;
    }


    public void collectMoney() {
        float sum_money_to_collect = 80 * (float)m_number_of_residents;
        m_cashbox += sum_money_to_collect;
    }



}
