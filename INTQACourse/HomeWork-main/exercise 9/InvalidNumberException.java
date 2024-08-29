package com.company;

public class InvalidNumberException extends RuntimeException{
    public InvalidNumberException(String message) {
        super(message);
    }
}
