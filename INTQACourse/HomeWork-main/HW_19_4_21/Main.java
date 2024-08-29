package com.company;

public class Main {

    public static void main(String[] args) {

        String nullString = null;

        try {
            printHalfSizeOfString(nullString);
            //NullPointerException
        }
        catch (NullPointerException ex) {
            System.out.println(ex);
        }
    }


    public static void printHalfSizeOfString(String sentence) {
        System.out.println(sentence.length() / 2);
    }


    public static void printHalfSizeOfStringThrowException(String sentence) {
        if (sentence == null) {
            throw new NullPointerException("String input is null");
        }
        else {
            System.out.println(sentence.length() / 2);
        }
    }


    public static void printHalfSizeOfStringThrowCustomException(String sentence) {
        if (sentence == null) {
            throw new WrongHalfStringInput("String input is null");
        }
        else {
            System.out.println(sentence.length() / 2);
        }
    }


}
