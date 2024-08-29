package com.company;

public class Box {

    private String m_content;
    private String m_owner;

    public void setM_content(String m_content) {
        this.m_content = m_content;
    }

    public Box(String m_content, String m_owner) {
        this.m_content = m_content;
        this.m_owner = m_owner;
    }

    public String getM_content() {
        return m_content;
    }

    public void setM_owner(String m_owner) {
        this.m_owner = m_owner;
    }

    public String getM_owner() {
        return m_owner;
    }

    @Override
    public String toString() {
        return "Box{" +
                "m_content='" + m_content + '\'' +
                ", m_owner='" + m_owner + '\'' +
                '}';
    }
}
