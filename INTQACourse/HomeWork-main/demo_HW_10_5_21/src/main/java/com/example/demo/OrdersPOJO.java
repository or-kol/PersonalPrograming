package com.example.demo;

public class OrdersPOJO {
    public int id;
    public String item_name;
    public int quantity;
    public double price;
    public String customer_name;

    public OrdersPOJO() {

    }

    public OrdersPOJO(int id, String item_name, int quantity, double price, String customer_name) {
        this.id = id;
        this.item_name = item_name;
        this.quantity = quantity;
        this.price = price;
        this.customer_name = customer_name;
    }

    @Override
    public String toString() {
        return "OrdersPOJO{" +
                "id=" + id +
                ", item_name='" + item_name + '\'' +
                ", quantity=" + quantity +
                ", price=" + price +
                ", customer_name='" + customer_name + '\'' +
                '}';
    }
}
