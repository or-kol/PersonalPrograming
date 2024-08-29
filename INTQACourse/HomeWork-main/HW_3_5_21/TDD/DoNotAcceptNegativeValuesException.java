package com.company;

public class DoNotAcceptNegativeValuesException extends RuntimeException {
    public DoNotAcceptNegativeValuesException(String message) {
        super(message);
    }
}
