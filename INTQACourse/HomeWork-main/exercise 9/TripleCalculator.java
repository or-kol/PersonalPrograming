package com.company;

public class TripleCalculator implements ITripleCalculator {

    private int m_boomCount;

    @Override
    public int calc(int number) {
        if (number == 0) {
            return 300;
        }
        else if (number % 7 == 0) {
            System.out.println("boom!");
            m_boomCount++;
            return 7;
        }

        return number * 3;
    }


}
