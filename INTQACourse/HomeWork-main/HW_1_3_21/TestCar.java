package com.company;

import org.junit.Test;

import static junit.framework.TestCase.assertEquals;

public class TestCar {

    @Test
    public void testCargetMaxNumOfPassengers() {
        Car c = new Car(TestData.testCargetMaxNumOfPassengers_wheels, TestData.testCargetMaxNumOfPassengers_model,
                TestData.testCargetMaxNumOfPassengers_doors);

        int actualresult = c.getMaxNumOfPassengers();

        assertEquals(TestData.testCargetMaxNumOfPassengers_expectedresult, actualresult);
    }

    @Test
    public void testCargetMaxSpeed() {
        Car c = new Car(TestData.testCargetMaxSpeed_wheels, TestData.testCargetMaxSpeed_model,
                TestData.testCargetMaxSpeed_doors);

        int actualresult = c.getMaxSpeed();

        assertEquals(TestData.testCargetMaxSpeed_expectedresult, actualresult);
    }
}
