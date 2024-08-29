package com.company;

import java.util.ArrayList;

public class NiceQueue <E>{

    ArrayList<E> m_queue = new ArrayList<>(20);

    public void enqueue(E element) {
        if (m_queue.size() <= 19) {
            m_queue.add(element);
        }
        else {
            System.out.println("Queue is full");
        }
    }

    public E dequeue(){
        if (m_queue.size() > 0) {
            E e = m_queue.get(m_queue.size() - 1);
            m_queue.remove(m_queue.size() - 1);
            return e;
        }
        else {
            return null;
        }
    }

    public void clear() {
        m_queue.clear();
    }

    public int count() {
        return m_queue.size();
    }

    public E next() {
        return m_queue.get(0);
    }
}
