package com.company;

public class PrintStringSize {

    public float printHalfSizeOfString(String sentence) {
        System.out.println(sentence.length() / 2);

        return sentence.length() / 2;
    }


    public float printHalfSizeOfStringThrowException(String sentence) {
        if (sentence == null) {
            throw new NullPointerException("String input is null");
        }
        else {
            System.out.println(sentence.length() / 2);
        }

        return sentence.length() / 2;
    }


    public float printHalfSizeOfStringThrowCustomException(String sentence) {
        if (sentence == null) {
            throw new WrongHalfStringInput("String input is null");
        }
        else {
            System.out.println(sentence.length() / 2);
        }

        return sentence.length() / 2;
    }

}
