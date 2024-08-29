package com.company;

import org.junit.Test;

import static junit.framework.TestCase.assertEquals;

public class TestNiceQueue {
    NiceQueue niceQueue = new NiceQueue();

    @Test
    public void testEnqueue(){
        niceQueue.enqueue(5);
        niceQueue.enqueue(6);

        assertEquals(TestData.testEnqueue_element1_expected_result, niceQueue.m_queue.get(0));
        assertEquals(TestData.testEnqueue_element2_expected_result, niceQueue.m_queue.get(1));
    }

    @Test
    public void testNoMoreThan20Elements(){
        for (int i = 0; i <= 23; i++) {
            niceQueue.enqueue(TestData.testNoMoreThan20Elements_elment);
        }

        int actual_result = niceQueue.m_queue.size();

        assertEquals(TestData.testNoMoreThan20Elements_Expected_Result, actual_result);
    }

    @Test
    public void testDequeueEmptyReturnNull(){

        Object actual_result = niceQueue.dequeue();

        assertEquals(TestData.testDequeueEmptyReturnNull_Expected_Result, actual_result);
    }

}
