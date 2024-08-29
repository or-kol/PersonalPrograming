package com.company;

import java.time.LocalTime;

public class CarsMechanic extends Mechanic{

    protected String[] m_car_types_i_can_repair;

    private Object Time;

    @Override
    public void repair() {
        System.out.println("Repairing car");
    }

    public void garageOpenOrClosed() {
        LocalTime now = LocalTime.now();
        LocalTime time1 = LocalTime.parse("07:00:00.00");
        LocalTime time2 = LocalTime.parse("17:00:00.00");
        if (now.isBefore(time1) || now.isAfter(time2)) {
            System.out.println("The garage is closed");
        }
    }

    public void replaceWheel() {
        System.out.println("Replacing the damaged wheel");
    }
}
