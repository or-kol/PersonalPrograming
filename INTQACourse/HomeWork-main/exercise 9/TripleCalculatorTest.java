package com.company;

import org.junit.Test;

import java.lang.reflect.Field;
import java.util.ArrayList;

import static junit.framework.TestCase.assertEquals;

public class TripleCalculatorTest {

    private Integer get_boomCount(TripleCalculator tc) {
        try {
            Integer fieldValue = null;
            Field privateStringField = null;
            privateStringField = TripleCalculator.class.getDeclaredField("m_boomCount");
            privateStringField.setAccessible(true);
            fieldValue = (Integer)privateStringField.get(tc);

            return fieldValue;
        }
        catch (NoSuchFieldException ex)
        {
            ex.printStackTrace();
        }
        catch (IllegalAccessException ex) {
            ex.printStackTrace();
        }

        return null;
    }



    @Test
    public void test_TripleCalculator_calc_pos1_mul(){
        TripleCalculator tc = new TripleCalculator();

        int actual_result = tc.calc(3);

        assertEquals(9, actual_result);
    }

    @Test
    public void test_TripleCalculator_calc_pos2_mul(){
        TripleCalculator tc = new TripleCalculator();

        int actual_result = tc.calc(9);

        assertEquals(27, actual_result);
    }


    @Test
    public void test_TripleCalculator_calc_pos_zeroInput(){
        TripleCalculator tc = new TripleCalculator();

        int actual_result = tc.calc(0);

        assertEquals(300, actual_result);
    }


    @Test
    public void test_TripleCalculator_calc_pos1_input7Mul(){
        TripleCalculator tc = new TripleCalculator();

        int actual_result = tc.calc(7);

        assertEquals(7, actual_result);
    }

    @Test
    public void test_TripleCalculator_calc_pos2_input7Mul(){
        TripleCalculator tc = new TripleCalculator();
        int boomCount = get_boomCount(tc);

        int actual_result = tc.calc(49);

        assertEquals(7, actual_result);
    }


    @Test
    public void test_TripleCalculator_calc_pos1_BoomCount(){
        TripleCalculator tc = new TripleCalculator();

        int actualCalcResult = tc.calc(7);
        int actualBoomCount = get_boomCount(tc);

        assertEquals(7, actualCalcResult);
        assertEquals(1, actualBoomCount);
    }

    @Test
    public void test_TripleCalculator_calc_pos2_BoomCount(){
        TripleCalculator tc = new TripleCalculator();

        int actualCalcResult1 = tc.calc(7);
        int actualCalcResult2 = tc.calc(49);
        int actualBoomCount = get_boomCount(tc);

        assertEquals(7, actualCalcResult1);
        assertEquals(7, actualCalcResult2);
        assertEquals(2, actualBoomCount);
    }





}
