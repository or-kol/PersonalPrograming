package com.company;

import org.junit.Test;

import static junit.framework.TestCase.assertEquals;

public class CellphoneTest {

    @Test
    public void test_Cellphone_addPhoneNumberToList_pos1(){
        Cellphone cellphone = new Cellphone();
        cellphone.addPhoneNumberToList("2565489");

        assertEquals(1, cellphone.phonebook.size());
        assertEquals ("2565489", cellphone.phonebook.get(0));
    }

    @Test (expected = InvalidNumberException.class)
    public void test_Cellphone_addPhoneNumberToList_neg1(){
        Cellphone cellphone = new Cellphone();
        cellphone.addPhoneNumberToList(null);
    }

    @Test (expected = PhoneBookIsFullException.class)
    public void test_Cellphone_addPhoneNumberToList_neg2(){
        Cellphone cellphone = new Cellphone();
        for (int i = 0; i < 10; i++) {
            cellphone.addPhoneNumberToList("56235489");
        }

        cellphone.addPhoneNumberToList("56235489");
    }



    @Test (expected = InvalidNumberException.class)
    public void test_Cellphone_callingNumber_neg1(){
        Cellphone cellphone = new Cellphone();
        cellphone.callingNumber(null);
    }


}
