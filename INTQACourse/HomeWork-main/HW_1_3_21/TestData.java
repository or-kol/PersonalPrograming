package com.company;

public class TestData {

    static final int testCargetMaxNumOfPassengers_wheels = 4;
    static final String testCargetMaxNumOfPassengers_model = "ABC";
    static final int testCargetMaxNumOfPassengers_doors = 5;
    static final int testCargetMaxNumOfPassengers_expectedresult = testCargetMaxNumOfPassengers_wheels + 1;


    static final int testCargetMaxSpeed_wheels = 4;
    static final String testCargetMaxSpeed_model = "DEF";
    static final int testCargetMaxSpeed_doors = 5;
    static final int testCargetMaxSpeed_expectedresult = testCargetMaxSpeed_doors * testCargetMaxSpeed_wheels * 10;

    static final int testMotorcyclegetMaxNumOfPassengers_wheels = 2;
    static final String testMotorcyclegetMaxNumOfPassengers_model = "GHI";
    static final float testMotorcyclegetMaxNumOfPassengers_handBreakSize = 2.3f;
    static final int testMotorcyclegetMaxNumOfPassengers_expectedresult = testMotorcyclegetMaxNumOfPassengers_wheels;


    static final int testMotorcyclegetMaxSpeed_wheels = 3;
    static final String testMotorcyclegetMaxSpeed_model = "JKL";
    static final float testMotorcyclegetMaxSpeed_handBreakSize = 3.3f;
    static final int testMotorcyclegetMaxSpeed_expectedresult = testMotorcyclegetMaxSpeed_wheels * 100;
}
