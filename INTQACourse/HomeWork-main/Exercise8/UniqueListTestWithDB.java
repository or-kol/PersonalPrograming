package com.company;

import org.junit.Test;

import java.util.ArrayList;

import static junit.framework.TestCase.assertEquals;

public class UniqueListTestWithDB {

    @Test
    public void testAdd() {
        UniqueListTestDataREPO repo = new UniqueListTestDataREPO("jdbc:sqlite:D:\\SQLite DB\\5.4.21\\5.4.21.db");
        ArrayList<UniqueListTestDataPOJO> calculatorPOJOS = repo.select("SELECT * FROM UniqueList");
        UniqueList uniqueList = new UniqueList();

        for (UniqueListTestDataPOJO one_row : calculatorPOJOS) {
            boolean actual_result =  uniqueList.add(one_row.Input);
            assertEquals(one_row.Result, actual_result);
        }
    }
}
