package com.company;

import java.util.Queue;

public class MyQueue {

    public void enqueue(Queue<Integer> queue, Integer x) {
        queue.add(x);
    }

    public Integer dequeue(Queue<Integer> queue) {
        return queue.poll();
    }

    public void clear(Queue<Integer> queue) {
        queue.clear();
    }

    public int count(Queue<Integer> queue) {
        return queue.size();
    }



}
