package com.company;


import java.util.ArrayList;

public class MyPositive10MulStack implements IMyPositive10MulStack{

    private ArrayList<Integer> m_items = new ArrayList<>();

    @Override
    public void push(int item) throws DoesNotDivideBy10Exception, NegativeInputException {
        if (item < 0) {
            throw new NegativeInputException("Input can't be ngative number!");
        }
        else {
            if (item % 10 == 0) {
                m_items.add(0, item);
            }
            else {
                throw new DoesNotDivideBy10Exception("The input does not divide by 10!");
            }
        }
    }

    @Override
    public int pop() throws EmptyStackException {
        int pop;
        if (m_items.size() > 0) {
            pop = m_items.get(0);
            m_items.remove(0);
        }
        else {
            throw new EmptyStackException("The stack is empty");
        }
        return pop;
    }

    @Override
    public int peek() throws EmptyStackException {
        int peek;
        if (m_items.size() > 0) {
            peek = m_items.get(0);
        }
        else {
            throw new EmptyStackException("The stack is empty");
        }
        return peek;
    }

    @Override
    public void clear() {
        m_items.clear();
    }

    @Override
    public int count() {
        return m_items.size();
    }
}
