package com.forest;

import com.creatures.Animal;
import com.creatures.Bear;
import com.creatures.Monkey;
import com.creatures.Tiger;

public class Main {

    public static void main(String[] args) {

        // Q14
        Animal ani = new Animal();
        Bear ber = new Bear();
        Monkey mon = new Monkey();
        Tiger tig = new Tiger();

        //Q15
        Drone dro = new Drone("aaa", 300f, 2000f, "asdf");
        dro.takeOff();
        // Extend Aircraft

    }
}
