package com.company;

import org.junit.Test;

import static junit.framework.TestCase.assertEquals;

public class TestPostOffice {

    PostOffice p = new PostOffice(TestData.testPostOffice_b0, TestData.testPostOffice_b1, TestData.testPostOffice_b2,
            TestData.testPostOffice_b3, TestData.testPostOffice_b4);

    @Test
    public void testNewBoxArrivedContent() {
        p.newBoxArrived(TestData.testNewBoxArrivedContent_new_b);

        assertEquals(TestData.testPostOfficeContent_expected_result, p.boxes.get(p.boxes.size() - 1).getM_content());

    }

    @Test
    public void testNewBoxArrivedOwner() {
        p.newBoxArrived(TestData.testNewBoxArrivedOwner_new_b);

        assertEquals(TestData.testNewBoxArrivedOwner_expected_result, p.boxes.get(p.boxes.size() - 1).getM_owner());

    }

    @Test
    public void testServeNextCustomer() {

        String actual_result = p.serveNextCustomer();

        assertEquals(TestData.testServeNextCustomer_expected_result, actual_result);


    }
}
