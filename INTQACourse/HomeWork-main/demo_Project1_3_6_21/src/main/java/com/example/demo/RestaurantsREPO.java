package com.example.demo;

import java.sql.*;
import java.util.ArrayList;

public class RestaurantsREPO {

    private String m_conn;

    public RestaurantsREPO(String m_conn) {
        this.m_conn = m_conn;
    }


    public ArrayList<RestaurantsPOJO> getAllRestaurants() {
        ArrayList<RestaurantsPOJO> restaurantsPOJO = new ArrayList<>();

        try (Connection conn = DriverManager.getConnection(m_conn)) {

            if (conn != null) {
                String sql = "SELECT * FROM Restaurants";

                Statement stmt = conn.createStatement();

                ResultSet rs = stmt.executeQuery(sql);

                while (rs.next()) {
                    RestaurantsPOJO r = new RestaurantsPOJO(
                            rs.getInt("Id"),
                            rs.getString("Name"),
                            rs.getString("Address"),
                            rs.getString("FoodType"),
                            rs.getDouble("MealPrice"));
                    restaurantsPOJO.add(r);
                }
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        return restaurantsPOJO;
    }


    public RestaurantsPOJO getById(int id) {
        ArrayList<RestaurantsPOJO> results = getAllRestaurants();
        if (results.size() > 0) {
            return results.get(id-1);
        }
        else {
            return null;
        }
    }


    public void update(String query) {
        try (Connection conn = DriverManager.getConnection(m_conn)) {

            if (conn != null) {
                String sql = query;

                Statement stmt = conn.createStatement();

                int result = stmt.executeUpdate(sql);
                System.out.println(result + " record updated.");
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }
}
