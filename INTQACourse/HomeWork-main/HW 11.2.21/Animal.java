package com.company;

import lombok.Getter;
import lombok.Setter;

public class Animal {

    private @Getter @Setter String m_name;
    private @Getter @Setter float m_size;
    private @Getter @Setter String m_color;

    public void goToVet() {
        System.out.println(String.format("%s, go to vet", m_name));
    }
}
