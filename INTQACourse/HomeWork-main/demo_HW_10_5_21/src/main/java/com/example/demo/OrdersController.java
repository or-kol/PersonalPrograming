package com.example.demo;

import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
public class OrdersController {

    private static OrdersREPO order = new OrdersREPO("jdbc:sqlite:D:\\SQLiteDB\\table10_5_21\\table10_5_21.db");

    @GetMapping("/order")
    public List<OrdersPOJO> getCustomers()
    {
        return order.getAllOrders();
    }


    @GetMapping("/order/{id}")
    public OrdersPOJO doGetOrderById(@PathVariable("id") int id) {
        return order.getById(id);
    }

    @PostMapping("/order")
    public String addOrder(@RequestBody OrdersPOJO o)
    {
        order.update(String.format(
                "INSERT INTO Orders (item_name, quantity, price, customer_name) VALUES ('%s', %d, %g, '%s')",
                o.item_name, o.quantity, o.price, o.customer_name));
        return "order added";
    }

    @PutMapping("/order/{id}")
    public String updateOrder(@PathVariable("id") int id, @RequestBody OrdersPOJO update) {
        order.update(String.format(
                "UPDATE Orders set item_name = '%s', quantity = %d, price = %g, customer_name = '%s' WHERE id = %d",
                update.item_name, update.quantity, update.price, update.customer_name, id));
        return "order updated";
    }

    @DeleteMapping("/order/{id}")
    public String deleteOrder(@PathVariable("id") int id) {
        order.update(String.format("DELETE FROM Orders WHERE ID = %d", id));
        return "order deleted";
    }

    @GetMapping("/orderprice/{id}")
    public double getOrderPrice(@PathVariable("id") int id) {
        OrdersPOJO orderPrice = order.getById(id);
        return orderPrice.price * (double)orderPrice.quantity;
    }

    @GetMapping("/totalprice")
    public double getTotalPrice() {
        List<OrdersPOJO> ordersList = order.getAllOrders();
        double totalPrice = 0;
        for (OrdersPOJO o : ordersList) {
            totalPrice += o.price * (double)o.quantity;
        }
        return totalPrice;
    }


}
