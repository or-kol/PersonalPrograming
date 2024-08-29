package com.company;

import java.util.Stack;

public class MyStack {

    public void push(Stack<Integer> stack, Integer x){
    stack.push(x);
    }

    public Integer pop(Stack<Integer> stack) {
        return stack.pop();
    }

    public int peek(Stack<Integer> stack){
        return stack.peek();
    }

    public void clear(Stack<Integer> stack) {
        stack.clear();
    }

    public int count(Stack<Integer> stack){
        return stack.size();
    }


}
