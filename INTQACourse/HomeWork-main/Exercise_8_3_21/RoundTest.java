package com.company;

import org.junit.Test;

import static junit.framework.TestCase.assertEquals;

public class RoundTest {

    RoundZero r = new RoundZero();

    @Test
    public void testZeroRoundUp() {
        float actualResult = r.roundUp(TestData.testZeroRoundUpF);

        assertEquals(TestData.testZeroRoundUpExpectedResult, actualResult);
    }

    @Test
    public void testOneRoundUp() {
        float actualResult = r.roundUp(TestData.testOneRoundUpF);

        assertEquals(TestData.testOneRoundUpExpectedResult, actualResult);
    }

    @Test
    public void testZeroPointLowRoundUp() {
        float actualResult = r.roundUp(TestData.testZeroPointLowRoundUpF);

        assertEquals(TestData.testZeroPointLowRoundUpExpectedResult, actualResult);
    }

    @Test
    public void testZeroPointHighRoundUp() {
        float actualResult = r.roundUp(TestData.testZeroPointHighRoundUpF);

        assertEquals(TestData.testZeroPointHighRoundUpExpectedResult, actualResult);
    }

    @Test
    public void testOverOneRoundUp() {
        float actualResult = r.roundUp(TestData.testOverOneRoundUpF);

        assertEquals(TestData.testOverOneRoundUpExpectedResult, actualResult);
    }

    @Test
    public void testUnderZeroRoundUp() {
        float actualResult = r.roundUp(TestData.testUnderZeroRoundUpF);

        assertEquals(TestData.testUnderZeroRoundUpExpectedResult, actualResult);
    }



    @Test
    public void testOneRoundDown() {
        float actualResult = r.roundDown(TestData.testOneRoundDownF);

        assertEquals(TestData.testOneRoundDownExpectedResult, actualResult);
    }

    @Test
    public void testZeroRoundDown() {
        float actualResult = r.roundDown(TestData.testZeroRoundDownF);

        assertEquals(TestData.testZeroRoundDownExpectedResult, actualResult);
    }

    @Test
    public void testZeroPointLowRoundDown() {
        float actualResult = r.roundDown(TestData.testZeroPointLowRoundDownF);

        assertEquals(TestData.testZeroPointLowRoundDownExpectedResult, actualResult);
    }

    @Test
    public void testZeroPointHighRoundDown() {
        float actualResult = r.roundDown(TestData.testZeroPointHighRoundDownF);

        assertEquals(TestData.testZeroPointHighRoundDownExpectedResult, actualResult);
    }

    @Test
    public void testOverOneRoundDown() {
        float actualResult = r.roundDown(TestData.testOverOneRoundDownF);

        assertEquals(TestData.testOverOneRoundDownExpectedResult, actualResult);
    }

    @Test
    public void testUnderZeroRoundDown() {
        float actualResult = r.roundDown(TestData.testUnderZeroRoundDownF);

        assertEquals(TestData.testUnderZeroRoundDownExpectedResult, actualResult);
    }



    @Test
    public void testOneRound() {
        float actualResult = r.round(TestData.testOneRoundF);

        assertEquals(TestData.testOneRoundExpectedResult, actualResult);
    }

    @Test
    public void testZeroRound() {
        float actualResult = r.round(TestData.testZeroRoundF);

        assertEquals(TestData.testZeroRoundExpectedResult, actualResult);
    }

    @Test
    public void testZeroPointFiveRound() {
        float actualResult = r.round(TestData.testZeroPointFiveRoundF);

        assertEquals(TestData.testZeroPointFiveRoundExpectedResult, actualResult);
    }

    @Test
    public void testZeroPointLowRound() {
        float actualResult = r.round(TestData.testZeroPointLowRoundF);

        assertEquals(TestData.testZeroPointLowRoundExpectedResult, actualResult);
    }

    @Test
    public void testZeroPointFourRound() {
        float actualResult = r.round(TestData.testZeroPointFourRoundF);

        assertEquals(TestData.testZeroPointFourRoundExpectedResult, actualResult);
    }

    @Test
    public void testZeroPointSixRound() {
        float actualResult = r.round(TestData.testZeroPointSixRoundF);

        assertEquals(TestData.testZeroPointSixRoundExpectedResult, actualResult);
    }

    @Test
    public void testZeroPointHighRound() {
        float actualResult = r.round(TestData.testZeroPointHighRoundF);

        assertEquals(TestData.testZeroPointHighRoundExpectedResult, actualResult);
    }

    @Test
    public void testOverOneRound() {
        float actualResult = r.round(TestData.testOverOneRoundF);

        assertEquals(TestData.testOverOneRoundExpectedResult, actualResult);
    }

    @Test
    public void testUnderZeroRound() {
        float actualResult = r.round(TestData.testUnderZeroRoundF);

        assertEquals(TestData.testUnderZeroRoundExpectedResult, actualResult);
    }
}
