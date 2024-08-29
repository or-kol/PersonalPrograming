package com.company;

import org.junit.Test;

import static junit.framework.TestCase.assertEquals;


public class CalculatorTest {

    @Test
    public void testAdd_small_numbers() {
        // Arrange
        Calculator calculator = new Calculator();

        // Act
        double actual_result = calculator.add(3, 4);

        // Assert
        // compare between actual result and expected result
        double expected_result = 7;

        assertEquals(expected_result, actual_result);
    }

    @Test
    public void testMolti_small_numbers() {
        Calculator calculator = new Calculator();

        double actual_result = calculator.multi(3, 4);

        double expected_result = 12;

        assertEquals(expected_result, actual_result);
    }


    @Test
    public void testmin_small_numbers() {
        Calculator calculator = new Calculator();

        double actual_result = calculator.min(3, 4);

        double expected_result = -1;

        assertEquals(expected_result, actual_result);
    }


    @Test
    public void testdiv_small_numbers() {
        Calculator calculator = new Calculator();

        double actual_result = calculator.div(6, 2);

        double expected_result = 3;

        assertEquals(expected_result, actual_result);
    }
}

