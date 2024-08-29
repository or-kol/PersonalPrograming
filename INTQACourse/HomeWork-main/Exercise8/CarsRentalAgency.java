package com.company;

import java.util.*;

public class CarsRentalAgency {

    static Random r = new Random();

    private ArrayList<String> cars;
    private Stack<String> workers;
    Queue<String> customers;
    private HashMap<String, Float> rentHourlyFee;

    private float income;

    public CarsRentalAgency(ArrayList<String> cars, Stack<String> workers, Queue<String> customers, HashMap<String, Float> rentHourlyFee) {
        this.cars = cars;
        this.workers = workers;
        this.customers = customers;
        this.rentHourlyFee = rentHourlyFee;
    }

    public void setCars(ArrayList<String> cars) {
        this.cars = cars;
    }

    public ArrayList<String> getCars() {
        return cars;
    }


    public void setWorkers(Stack<String> workers) {
        this.workers = workers;
    }

    public Stack<String> getWorkers() {
        return workers;
    }


    public void setCustomers(Queue<String> customers) {
        this.customers = customers;
    }

    public Queue<String> getCustomers() {
        return customers;
    }


    public void setRentHourlyFee(HashMap<String, Float> rentHourlyFee) {
        this.rentHourlyFee = rentHourlyFee;
    }

    public HashMap<String, Float> getRentHourlyFee() {
        return rentHourlyFee;
    }


    public void setIncome(float income) {
        this.income = income;
    }

    public float getIncome() {
        return income;
    }


    public void rentACar() {
        if (customers.size() == 0) {
            System.out.println("No customers waiting...");
        } else {
            if (workers.size() == 0) {
                System.out.println("Sorry, all our workers are busy right now");
            } else {
                if (cars.size() == 0) {
                    System.out.println("Sorry, we have no cars available right now");
                } else {
                    String next_customer = customers.poll();
                    String worker = workers.pop();
                    String car = cars.get(r.nextInt(cars.size()));
                    cars.remove(car);

                    Float car_fee = rentHourlyFee.get(car);
                    int rent_time = r.nextInt(12) + 1;
                    float rental_cost = car_fee * (float) rent_time;
                    income += rental_cost;

                    System.out.println(String.format("The customer %s has rented car %s for %d hours", next_customer, car, rent_time));

                    workers.add(worker);
                }
            }

        }
    }


    public void returnACar (String customer, String car) {
        if (workers.size() == 0) {
            System.out.println("Sorry, all our workers are busy right now");
        }
        else {
            String worker = workers.pop();
            cars.add(car);

            System.out.println(String.format("The customer %s has returned the car %s", customer, car));

            workers.add(worker);
        }
    }





}
