package com.company;

public class PhoneBookIsFullException extends RuntimeException{
    public PhoneBookIsFullException(String message) {
        super(message);
    }
}
