package com.example.demo;

public class RestaurantsDTO {
    public int Id;
    public String Name;
    public String Address;
    public String FoodType;
    public double MealPrice;


    public RestaurantsDTO() {

    }

    public RestaurantsDTO(int id, String name, String address, String foodType, double mealPrice) {
        Id = id;
        Name = name;
        Address = address;
        FoodType = foodType;
        MealPrice = mealPrice;
    }

    @Override
    public String toString() {
        return "RestaurantsDTO{" +
                "Id=" + Id +
                ", Name='" + Name + '\'' +
                ", Address='" + Address + '\'' +
                ", FoodType='" + FoodType + '\'' +
                ", MealPrice=" + MealPrice +
                '}';
    }


}
