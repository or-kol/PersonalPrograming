package com.company;

import junit.framework.Assert;
import org.junit.Test;

import java.util.HashMap;

import static junit.framework.TestCase.assertEquals;


public class TestLibrary {

    @Test
    public void testSearchBooksBook1() {
        Library library = new Library(new HashMap<>());
        library.booksMap.put(TestData.mapCreation_Name_Book1, TestData.mapCreation_Shelf_Book1);
        library.booksMap.put(TestData.mapCreation_Name_Book2, TestData.mapCreation_Shelf_Book2);
        library.booksMap.put(TestData.mapCreation_Name_Book3, TestData.mapCreation_Shelf_Book3);

        Integer actual_result = library.searchForBook(TestData.mapCreation_Name_Book1);

        assertEquals(TestData.testSearchBooksBook1_Expected_Result, actual_result);
    }

    @Test
    public void testSearchBooksBook2() {
        Library library = new Library(new HashMap<>());
        library.booksMap.put(TestData.mapCreation_Name_Book1, TestData.mapCreation_Shelf_Book1);
        library.booksMap.put(TestData.mapCreation_Name_Book2, TestData.mapCreation_Shelf_Book2);
        library.booksMap.put(TestData.mapCreation_Name_Book3, TestData.mapCreation_Shelf_Book3);

        Integer actual_result = library.searchForBook(TestData.mapCreation_Name_Book2);

        assertEquals(TestData.testSearchBooksBook2_Expected_Result, actual_result);
    }

    @Test
    public void testSearchBooksBook3() {
        Library library = new Library(new HashMap<>());
        library.booksMap.put(TestData.mapCreation_Name_Book1, TestData.mapCreation_Shelf_Book1);
        library.booksMap.put(TestData.mapCreation_Name_Book2, TestData.mapCreation_Shelf_Book2);
        library.booksMap.put(TestData.mapCreation_Name_Book3, TestData.mapCreation_Shelf_Book3);

        Integer actual_result = library.searchForBook(TestData.mapCreation_Name_Book3);

        assertEquals(TestData.testSearchBooksBook3_Expected_Result, actual_result);
    }

    @Test
    public void testSearchBooksNotExist() {
        Library library = new Library(new HashMap<>());
        library.booksMap.put(TestData.mapCreation_Name_Book1, TestData.mapCreation_Shelf_Book1);
        library.booksMap.put(TestData.mapCreation_Name_Book2, TestData.mapCreation_Shelf_Book2);
        library.booksMap.put(TestData.mapCreation_Name_Book3, TestData.mapCreation_Shelf_Book3);

        Integer actual_result = library.searchForBook(TestData.testSearchBooksNotExist_Name_BookNotExist);

        assertEquals(TestData.testSearchBooksNotExist_Expected_Result, actual_result);
    }
}
