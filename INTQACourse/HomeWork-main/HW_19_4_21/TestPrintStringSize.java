package com.company;

import org.junit.Test;

import static junit.framework.TestCase.assertEquals;

public class TestPrintStringSize {

    static PrintStringSize printStringSize = new PrintStringSize();


    @Test
    public void printHalfSizeOfStringPositiveFlow() {

        float actual_result = printStringSize.printHalfSizeOfString("abcd");

        float expected_result = 2f;

        assertEquals(expected_result, actual_result);
    }

    @Test(expected = NullPointerException.class)
    public void printHalfSizeOfStringNegativeFlow() {

        float actual_result = printStringSize.printHalfSizeOfString(null);
    }



    @Test
    public void printHalfSizeOfStringThrowExceptionPositiveFlow() {

        float actual_result = printStringSize.printHalfSizeOfStringThrowException("abcd");

        float expected_result = 2f;

        assertEquals(expected_result, actual_result);
    }

    @Test(expected = NullPointerException.class)
    public void printHalfSizeOfStringThrowExceptionNegativeFlow() {

        float actual_result = printStringSize.printHalfSizeOfStringThrowException(null);
    }




    @Test
    public void printHalfSizeOfStringThrowCustomExceptionPositiveFlow() {

        float actual_result = printStringSize.printHalfSizeOfStringThrowCustomException("abcd");

        float expected_result = 2f;

        assertEquals(expected_result, actual_result);
    }

    @Test(expected = WrongHalfStringInput.class)
    public void printHalfSizeOfStringThrowCustomExceptionNegativeFlow() {

        float actual_result = printStringSize.printHalfSizeOfStringThrowCustomException(null);
    }





}
