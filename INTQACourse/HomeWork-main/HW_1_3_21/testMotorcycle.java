package com.company;

import org.junit.Test;

import static junit.framework.TestCase.assertEquals;

public class testMotorcycle {

    @Test
    public void testMotorcyclegetMaxNumOfPassengers() {
        Motorcycle m = new Motorcycle(TestData.testMotorcyclegetMaxNumOfPassengers_wheels, TestData.testMotorcyclegetMaxNumOfPassengers_model,
                TestData.testMotorcyclegetMaxNumOfPassengers_handBreakSize);

        int actualresult = m.getMaxNumOfPassengers();

        assertEquals(TestData.testMotorcyclegetMaxNumOfPassengers_expectedresult, actualresult);
    }

    @Test
    public void testMotorcyclegetMaxSpeed() {
        Motorcycle m = new Motorcycle(TestData.testMotorcyclegetMaxSpeed_wheels, TestData.testMotorcyclegetMaxSpeed_model,
                TestData.testMotorcyclegetMaxSpeed_handBreakSize);

        int actualresult = m.getMaxSpeed();

        assertEquals(TestData.testMotorcyclegetMaxSpeed_expectedresult, actualresult);
    }


}
