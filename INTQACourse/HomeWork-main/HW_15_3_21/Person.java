package com.company;

import java.time.LocalDateTime;

public class Person {

    protected String m_name;
    protected LocalDateTime m_birthday;
    protected int m_age;

    public Person(String m_name, LocalDateTime m_birthday, int m_age) {
        this.m_name = m_name;
        this.m_birthday = m_birthday;
        this.m_age = m_age;
    }

    @Override
    public String toString() {
        return "Person{" +
                "m_name='" + m_name + '\'' +
                ", m_birthday=" + m_birthday +
                ", m_age=" + m_age +
                '}';
    }
}
