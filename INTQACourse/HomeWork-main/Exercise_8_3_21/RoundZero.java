package com.company;

public class RoundZero {

    public float roundUp(float f) {
        if (f == 0) {
            return 0;
        }
        else if (f > 0 && f <= 1) {
            return 1;
        }
        System.out.println("number must be between 0-1");
        return -1;
    }

    public float roundDown(float f) {
        if (f == 1) {
            return 1;
        }
        else if (f < 1 && f >= 0) {
            return 0;
        }
        System.out.println("number must be between 0-1");
        return -1;
    }

    public float round(float f) {
        if (f >= 0 && f < 0.5) {
            return 0;
        }
        else if (f >= 0.5 && f <= 1) {
            return 1;
        }
        System.out.println("number must be between 0-1");
        return -1;
    }
}
