package com.company;

public class CellPhone extends ElectricDevice{

    protected String m_brand;

    public CellPhone(String m_brand) {
        super(true);
        this.m_brand = m_brand;
    }


    @Override
    public void useDevice() {
        System.out.println("Talking on the phone");
    }

    @Override
    public void fixDevice() {
        if (m_is_faulty == true) {
            System.out.println("Fixing cellphone");
            m_is_faulty = false;
        }
        else {
            System.out.println("This cellphone is working properly");
        }
    }

    // can't override "insertNewBatteries" function since it is final.
}
