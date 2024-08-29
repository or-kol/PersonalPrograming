package com.company;

public class NotEnougthPlayersException extends RuntimeException{
    public NotEnougthPlayersException(String message) {
        super(message);
    }
}
