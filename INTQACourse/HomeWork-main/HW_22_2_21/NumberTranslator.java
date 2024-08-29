package com.company;

public class NumberTranslator {

    public String translateNumber(int a) {
        String x = "0";
        switch (a) {
            case 1:
                x = "One";
                break;
            case 2:
                x = "Two";
                break;
            case 3:
                x = "Three";
                break;
            case 4:
                x = "Four";
                break;
            case 5:
                x = "Five";
                break;
        }
        return x;
    }
}
