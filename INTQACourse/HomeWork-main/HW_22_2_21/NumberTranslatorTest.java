package com.company;

import org.junit.Test;

import static junit.framework.TestCase.assertEquals;

public class NumberTranslatorTest {

    @Test
    public void testNumber_One() {
        NumberTranslator numberTranslator = new NumberTranslator();

        String actual_result = numberTranslator.translateNumber(1);

        String expected_result = "One";

        assertEquals(expected_result, actual_result);
    }


    @Test
    public void testNumber_Two() {
        NumberTranslator numberTranslator = new NumberTranslator();

        String actual_result = numberTranslator.translateNumber(2);

        String expected_result = "Two";

        assertEquals(expected_result, actual_result);
    }


    @Test
    public void testNumber_Three() {
        NumberTranslator numberTranslator = new NumberTranslator();

        String actual_result = numberTranslator.translateNumber(3);

        String expected_result = "Three";

        assertEquals(expected_result, actual_result);
    }


    @Test
    public void testNumber_Four() {
        NumberTranslator numberTranslator = new NumberTranslator();

        String actual_result = numberTranslator.translateNumber(4);

        String expected_result = "Four";

        assertEquals(expected_result, actual_result);
    }


    @Test
    public void testNumber_Five() {
        NumberTranslator numberTranslator = new NumberTranslator();

        String actual_result = numberTranslator.translateNumber(5);

        String expected_result = "Five";

        assertEquals(expected_result, actual_result);
    }
}
