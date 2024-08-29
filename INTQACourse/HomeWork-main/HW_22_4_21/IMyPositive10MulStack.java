package com.company;

public interface IMyPositive10MulStack {

    void push(int item) throws DoesNotDivideBy10Exception, NegativeInputException;
    int pop () throws EmptyStackException;
    int peek() throws EmptyStackException;
    void clear();
    int count();
}
