package com.company;

import java.util.ArrayList;

public class Cellphone {

    public ArrayList<String> phonebook = new ArrayList<>(10);


    public void addPhoneNumberToList(String phoneNum) {
        if (phoneNum == null) {
            throw new InvalidNumberException("Number is null!");
        }
        else if (phonebook.size() < 10){
            phonebook.add(phoneNum);
        }
        else {
            throw new PhoneBookIsFullException("Phonebook already contain 10 numbers");
        }
    }


    public void callingNumber(String phoneNum) {
        if (phoneNum == null) {
            throw new InvalidNumberException("Number is null!");
        }

        System.out.println(String.format("Calling %s", phoneNum));
    }



}
