package com.company;


import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {

        //Q1 - by using "override". using the same name in the derived class function.
        //      we want to do that when we need the same function in a derived class, but it's implementation is different in the derived class.

        //Q4 - when a function receives a "higher" class of the tree and it allows us to use all the forms that extends this class.


        // Q5
        Teacher math = new MathTeacher();
        Teacher history = new HistoryTeacher();


        //Q6.a - no, because the class "Teacher" does not contain the field "math_skills".

        //Q7.a - abstract class is a class we can't instance of.
        //Q7.b - yes.

        //Q8.a - abstract method is a method without body. and it's a debt all derived classes must fill.
        //Q8.b - no.
        //Q8.c - no.

        //Q9.a - no.
        //Q9.b - yes.


        //Q11
        ElectricDevice tv = new TV(32);
        ElectricDevice phone = new CellPhone("Samsung");


        //Q12.a - no.
        //Q12.b - don't have an example.

        //Q13 - It is a collection of abstract methods.

        //Q14.a - all functions in interface are public.
        //Q14.b - yes.
        //Q14.c - yes.
        //Q14.d - yes.

        //Q16 - we will use abstract class when we need members and when all the functions apply to one inheritance tree.


        //Q17
        IPlayer guitar = new GuitarPlayer();
        IPlayer piano = new PianoPlayer();


        //Q18 - ArrayList is a list of variables, it differs from Array brcause we can always add or delete new members.


        //Q19
        ArrayList<Integer> num19 = new ArrayList<>();
        num19.add(5);
        num19.add(7);
        num19.add(9);

        System.out.println(num19);
        System.out.println(num19.get(0));

        num19.remove(1);

        System.out.println(num19.indexOf(9));


        //Q21.a - when it's a test.
        //Q21.b - compares two variables if they are equal or not.

    }



    //Q17
    public static void startMusicSow(Player p) {
        p.play();

        if (p instanceof GuitarPlayer) {
            ((GuitarPlayer) p).rockAndRoll();
        }
        else if (p instanceof PianoPlayer) {
            ((PianoPlayer) p).playJazz();
        }
    }



    //Q11
    public static void repairElectricDevice(ElectricDevice x) {
    if (x.m_works_on_batteries == true) {
        x.insertNewBatteries();
    }
    else if (x.m_is_faulty == false) {
        return;
    }
    else {
        x.fixDevice();

        if (x instanceof TV) {
            System.out.println(((TV) x).m_screen_size);
        }
        else if (x instanceof CellPhone) {
            System.out.println(((CellPhone) x).m_brand);
        }

        System.out.println("Fixing is done");
        }
    }



    //Q6.b
    public static void identifyTeacher(Teacher t) {
        if (t instanceof MathTeacher) {
            System.out.println("Math teacher");
        }
        else if (t instanceof HistoryTeacher) {
            System.out.println("History teacher");
        }
    }

    //Q6.c
    public static void identifyTeacher2(Teacher t) {
        if (t instanceof MathTeacher) {
            System.out.println(((MathTeacher) t).m_math_skills);
        }
        else if (t instanceof HistoryTeacher) {
            System.out.println(((HistoryTeacher) t).m_field_of_profession);
        }
    }

}
