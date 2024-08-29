package com.company;

public class RoundedSizeRectangle {

    private int m_width;
    private int m_height;

    public RoundedSizeRectangle(float m_width, float m_height) {
        if (m_width < 0) {
            throw new DoNotAcceptNegativeValuesException("Negative number entered!");
        }
        else if (m_width - (int)m_width <= 0.5) {
            this.m_width = (int)m_width;
        }
        else {
            this.m_width = (int)m_width + 1;
        }

        if (m_height < 0) {
            throw new DoNotAcceptNegativeValuesException("Negative number entered!");
        }
        else if (m_height - (int)m_height <= 0.5) {
            this.m_height = (int)m_height;
        }
        else {
            this.m_height = (int)m_height + 1;
        }
    }


    public int getArea() {
        return this.m_width * this.m_height;
    }
}
