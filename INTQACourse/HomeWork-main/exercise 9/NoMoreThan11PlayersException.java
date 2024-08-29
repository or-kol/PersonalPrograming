package com.company;

public class NoMoreThan11PlayersException extends RuntimeException{
    public NoMoreThan11PlayersException(String message) {
        super(message);
    }
}
