package com.company;

import java.util.ArrayList;
import java.util.HashMap;

public class TestData {

        // Q13 Test
        static final Box testPostOffice_b0 = new Box("AAA", "BBB");
        static final Box testPostOffice_b1 = new Box("CCC", "DDD");
        static final Box testPostOffice_b2 = new Box("EEE", "FFF");
        static final Box testPostOffice_b3 = new Box("GGG", "HHH");
        static final Box testPostOffice_b4 = new Box("III", "JJJ");


        static final Box testNewBoxArrivedContent_new_b = new Box("YYY", "XXX");
        static final String testPostOfficeContent_expected_result = "YYY";

        static final Box testNewBoxArrivedOwner_new_b = new Box("YYY", "XXX");
        static final String testNewBoxArrivedOwner_expected_result = "XXX";



        static final String testServeNextCustomer_expected_result = testPostOffice_b0.getM_content();;


        //Q16 Test

        static final String mapCreation_Name_Book1 = "aaa";
        static final Integer mapCreation_Shelf_Book1 = 1;
        static final String mapCreation_Name_Book2 = "bbb";
        static final Integer mapCreation_Shelf_Book2 = 2;
        static final String mapCreation_Name_Book3 = "ccc";
        static final Integer mapCreation_Shelf_Book3 = 3;

        static final Integer testSearchBooksBook1_Expected_Result = mapCreation_Shelf_Book1;
        static final Integer testSearchBooksBook2_Expected_Result = mapCreation_Shelf_Book2;
        static final Integer testSearchBooksBook3_Expected_Result = mapCreation_Shelf_Book3;

        static final String testSearchBooksNotExist_Name_BookNotExist = "zzz";
        static final Integer testSearchBooksNotExist_Expected_Result = -1;


        //Q18
        static final int testEnqueue_element1 = 5;
        static final int testEnqueue_element2 = 6;

        static final int testEnqueue_element1_expected_result = testEnqueue_element1;
        static final int testEnqueue_element2_expected_result = testEnqueue_element2;

        static final int testNoMoreThan20Elements_elment = 1;
        static final int testNoMoreThan20Elements_Expected_Result = 20;

        static final Object testDequeueEmptyReturnNull_Expected_Result = null;






}
