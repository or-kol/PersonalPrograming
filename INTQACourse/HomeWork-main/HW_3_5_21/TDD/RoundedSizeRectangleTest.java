package com.company;

import org.junit.Test;

import java.lang.reflect.Field;

import static junit.framework.TestCase.assertEquals;

public class RoundedSizeRectangleTest {

    private Integer get_m_width(RoundedSizeRectangle rsr) {
        try {
            Integer fieldValue = null;
            Field privateStringField = null;
            privateStringField = RoundedSizeRectangle.class.getDeclaredField("m_width");
            privateStringField.setAccessible(true);
            fieldValue = (Integer) privateStringField.get(rsr);

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

    private Integer get_m_height(RoundedSizeRectangle rsr) {
        try {
            Integer fieldValue = null;
            Field privateStringField = null;
            privateStringField = RoundedSizeRectangle.class.getDeclaredField("m_height");
            privateStringField.setAccessible(true);
            fieldValue = (Integer) privateStringField.get(rsr);

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
    public void test_ctor_pos1(){
        RoundedSizeRectangle rsr = new RoundedSizeRectangle(5.1f, 5.9f);

        int actual_m_width = get_m_width(rsr);
        int actual_m_height = get_m_height(rsr);

        assertEquals(5, actual_m_width);
        assertEquals(6, actual_m_height);
    }


    @Test
    public void test_ctor_pos2(){
        RoundedSizeRectangle rsr = new RoundedSizeRectangle(5.5f, 5.6f);

        int actual_m_width = get_m_width(rsr);
        int actual_m_height = get_m_height(rsr);

        assertEquals(5, actual_m_width);
        assertEquals(6, actual_m_height);
    }


    @Test
    public void test_ctor_pos3(){
        RoundedSizeRectangle rsr = new RoundedSizeRectangle(5.9f, 5.1f);

        int actual_m_width = get_m_width(rsr);
        int actual_m_height = get_m_height(rsr);

        assertEquals(6, actual_m_width);
        assertEquals(5, actual_m_height);
    }

    @Test
    public void test_ctor_pos4(){
        RoundedSizeRectangle rsr = new RoundedSizeRectangle(5.6f, 5.5f);

        int actual_m_width = get_m_width(rsr);
        int actual_m_height = get_m_height(rsr);

        assertEquals(6, actual_m_width);
        assertEquals(5, actual_m_height);
    }

    @Test (expected = DoNotAcceptNegativeValuesException.class)
    public void test_ctor_widthNegativeValue_neg1(){
        RoundedSizeRectangle rsr = new RoundedSizeRectangle(-5.6f, 5.5f);
    }

    @Test (expected = DoNotAcceptNegativeValuesException.class)
    public void test_ctor_heightNegativeValue_neg1() {
        RoundedSizeRectangle rsr = new RoundedSizeRectangle(5.6f, -5.5f);
    }

    @Test
    public void test_getArea_pos1(){
        RoundedSizeRectangle rsr = new RoundedSizeRectangle(5.6f, 5.5f);

        int actualArea = rsr.getArea();

        assertEquals(30, actualArea);
    }


}
