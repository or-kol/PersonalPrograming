package com.example.demo;

import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.List;

@RestController
public class CustomerController {

    private static List<Customer> m_customers = new ArrayList<>();

    static {
        m_customers.add(new Customer(1, "Steve", "New York"));
        m_customers.add(new Customer(2, "Alex", "Texas"));
        m_customers.add(new Customer(3, "Anna", "Miami"));
    }

    @GetMapping("/customer")
    public List<Customer> getAllCustomers () {
        return m_customers;
    }

    @GetMapping("/customer/{id}")
    public Customer getCustomerByID (@PathVariable("id") int id) {
        for (Customer c : m_customers) {
            if (c.getId() == id){
                return c;
            }
        }

        return null;
    }

    @PostMapping("/customer")
    public String addCustomer (@RequestBody Customer c) {
        m_customers.add(c);
        return String.format("Customer added: ID: %d Name: %s.", c.getId(), c.getName());
    }

    @DeleteMapping("/customer/{id}")
    public String deleteCustomer (@PathVariable("id") int id) {
        for (Customer c : m_customers) {
            if (c.getId() == id){
                m_customers.remove(c);
                return String.format("Customer %d was deleted", id);
            }
        }
        return String.format("Customer with ID: %d was not found", id);
    }

    @PutMapping("/customer/{id}")
    public String updateCustomer (@PathVariable("id") int id, @RequestBody Customer sent) {
        for (Customer c : m_customers) {
            if (c.getId() == id){
                Customer old = c;
                c.setId(sent.getId());
                c.setName(sent.getName());
                c.setAddress(sent.getAddress());
                return String.format(String.format("Customer was updated to: %s", sent));
            }
        }
        return String.format("Customer with ID: %d was not found", id);
    }


}
