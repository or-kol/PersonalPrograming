package com.company;

import org.junit.Test;

import java.lang.reflect.Field;
import java.util.ArrayList;

import static junit.framework.TestCase.assertEquals;

public class MyPositive10mulStackTest {

    private ArrayList<Integer> get_m_items(MyPositive10MulStack stack) {
        try {
            ArrayList<Integer> fieldValue = null; // m_items
            Field privateStringField = null;
            privateStringField = MyPositive10MulStack.class.
                    getDeclaredField("m_items");
            privateStringField.setAccessible(true);
            fieldValue = (ArrayList<Integer>) privateStringField.get(stack);

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



    // positive flows

    @Test
    public void test_MyPositive10mulStack_push_pos1() throws DoesNotDivideBy10Exception, NegativeInputException, EmptyStackException {
        MyPositive10MulStack stack = new MyPositive10MulStack();
        stack.push(10);

        // non atomic
        assertEquals(1, stack.count());
        assertEquals (10, stack.peek());

        // atomic
        // how to check the push without using the interface!
        ArrayList<Integer> m_items = get_m_items(stack);

        assertEquals(1, m_items.size());
        assertEquals (10, (int)m_items.get(0));
    }


    @Test
    public void test_MyPositive10mulStack_pop_pos1() throws EmptyStackException {
        MyPositive10MulStack stack = new MyPositive10MulStack();

        //stack.push(10);
        ArrayList<Integer> m_items = get_m_items(stack);

        m_items.add(10);


        int actual_result = stack.pop();

        // non atomic
        assertEquals(0, stack.count());
        assertEquals(10, actual_result);

        // atomic
        // how to check the push without using the interface!
        assertEquals(0, m_items.size());
        assertEquals (10, actual_result);
    }


    @Test
    public void test_MyPositive10mulStack_pop_pos2() throws EmptyStackException {
        MyPositive10MulStack stack = new MyPositive10MulStack();
        // stack.push(10);
        // stack.push(20);
        ArrayList<Integer> m_items = get_m_items(stack);

        m_items.add(0, 10);
        m_items.add(1, 20);


        int actual_result = stack.pop();

        // non atomic
        assertEquals(1, stack.count());
        assertEquals(10, actual_result);

        // atomic
        // how to check the push without using the interface!
        assertEquals(1, m_items.size());
        assertEquals (10, actual_result);
    }


    @Test
    public void test_MyPositive10mulStack_peek_pos1() throws EmptyStackException {
        MyPositive10MulStack stack = new MyPositive10MulStack();
        // stack.push(10);
        ArrayList<Integer> m_items = get_m_items(stack);
        m_items.add(10);

        int actual_result = stack.peek();

        // non atomic
        assertEquals(1, stack.count());
        assertEquals(10, actual_result);

        // atomic
        // how to check the push without using the interface!
        assertEquals(1, m_items.size());
        assertEquals (10, actual_result);

    }

    @Test
    public void test_MyPositive10mulStack_peek_pos2() throws EmptyStackException {
        MyPositive10MulStack stack = new MyPositive10MulStack();
        //stack.push(10);
        //stack.push(20);
        ArrayList<Integer> m_items = get_m_items(stack);

        m_items.add(0, 10);
        m_items.add(1, 20);

        int actual_result = stack.peek();

        // non atomic
        assertEquals(2, stack.count());
        assertEquals(10, actual_result);

        // atomic
        // how to check the push without using the interface!
        assertEquals(2, m_items.size());
        assertEquals (10, actual_result);
    }


    @Test
    public void test_MyPositive10mulStack_clear_pos1()
    {
        MyPositive10MulStack stack = new MyPositive10MulStack();
        //stack.push(10);
        ArrayList<Integer> m_items = get_m_items(stack);
        m_items.add(10);

        stack.clear();

        // non atomic
        assertEquals(0, stack.count());

        // atomic
        // how to check the push without using the interface!
        assertEquals(0, m_items.size());
    }

    @Test
    public void test_MyPositive10mulStack_clear_pos2()
    {
        MyPositive10MulStack stack = new MyPositive10MulStack();
        stack.clear();

        // non atomic
        assertEquals(0, stack.count());

        // atomic
        // how to check the push without using the interface!
        ArrayList<Integer> m_items = get_m_items(stack);
        assertEquals(0, m_items.size());
    }



    @Test
    public void test_MyPositive10mulStack_count_pos1()
    {
        MyPositive10MulStack stack = new MyPositive10MulStack();
        int actual_result = stack.count();

        // non atomic
        assertEquals(0, actual_result);
    }

    @Test
    public void test_MyPositive10mulStack_count_pos2()
    {
        MyPositive10MulStack stack = new MyPositive10MulStack();
        //stack.push(10);
        //stack.push(20);
        ArrayList<Integer> m_items = get_m_items(stack);

        m_items.add(0, 10);
        m_items.add(1, 20);

        int actual_result = stack.count();

        // non atomic
        assertEquals(2, actual_result);
    }


    // negative flows
    @Test (expected = NegativeInputException.class)
    public void test_MyPositive10mulStack_push_neg_NegativeInputException() throws DoesNotDivideBy10Exception,
            NegativeInputException {
        MyPositive10MulStack stack = new MyPositive10MulStack();
        stack.push(-10);
    }

    @Test (expected = DoesNotDivideBy10Exception.class)
    public void test_MyPositive10mulStack_push_neg_DoesNotDivideBy10Exception() throws DoesNotDivideBy10Exception,
            NegativeInputException {
        MyPositive10MulStack stack = new MyPositive10MulStack();
        stack.push(5);
    }

    @Test (expected = EmptyStackException.class)
    public void test_MyPositive10mulStack_pop_neg_EmptyStackException() throws EmptyStackException {
        MyPositive10MulStack stack = new MyPositive10MulStack();
        stack.pop();
    }

    @Test (expected = EmptyStackException.class)
    public void test_MyPositive10mulStack_peek_neg_EmptyStackException() throws EmptyStackException {
        MyPositive10MulStack stack = new MyPositive10MulStack();
        stack.peek();
    }



}