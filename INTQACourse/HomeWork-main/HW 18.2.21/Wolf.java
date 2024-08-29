package com.company;

public class Wolf extends Dog{

    protected String nameOfPack;

    public Wolf(String m_name, String m_favoriteDogFood, String nameOfPack) {
        super(m_name, m_favoriteDogFood);
        this.nameOfPack = nameOfPack;
    }

    @Override
    public String toString() {
        return super.toString() +
                "Wolf{" +
                "nameOfPack='" + nameOfPack + '\'' +
                '}';
    }
}
