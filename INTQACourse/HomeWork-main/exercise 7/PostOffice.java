package com.company;

import java.net.PortUnreachableException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;

public class PostOffice {

    ArrayList<Box> boxes;
    Queue<String> customers;


    public PostOffice(Box b0, Box b1, Box b2, Box b3, Box b4) {
        this.boxes = new ArrayList<>(5);
        this.customers = new ArrayDeque<>();

        boxes.add(b0);
        boxes.add(b1);
        boxes.add(b2);
        boxes.add(b3);
        boxes.add(b4);

        customers.add(boxes.get(0).getM_owner());
        customers.add(boxes.get(1).getM_owner());
        customers.add(boxes.get(2).getM_owner());
        customers.add(boxes.get(3).getM_owner());
        customers.add(boxes.get(4).getM_owner());
    }


    @Override
    public String toString() {
        return "PostOffice{" +
                "boxes=" + boxes +
                ", customers=" + customers +
                '}';
    }

    public void newBoxArrived(Box new_b) {
        boxes.add(new Box(new_b.getM_content(), new_b.getM_owner()));
    }

    public String serveNextCustomer() {
        String new_customer = customers.poll();
        System.out.println(new_customer);

        String b_con = boxes.get(0).getM_content();
        System.out.println(b_con);

        boxes.remove(0);

        return b_con;
    }
}
