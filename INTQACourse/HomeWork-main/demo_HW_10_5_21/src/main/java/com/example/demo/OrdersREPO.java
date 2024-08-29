package com.example.demo;

import java.sql.*;
import java.util.ArrayList;

public class OrdersREPO {

    private String m_conn;

    public OrdersREPO(String m_conn) {
        this.m_conn = m_conn;
    }


    public ArrayList<OrdersPOJO> getAllOrders() {
        ArrayList<OrdersPOJO> OrdersPOJO = new ArrayList<>();

        try (Connection conn = DriverManager.getConnection(m_conn)) {

            if (conn != null) {
                String sql = "SELECT * FROM Orders";

                Statement stmt = conn.createStatement();

                ResultSet rs = stmt.executeQuery(sql);

                while (rs.next()) {
                    OrdersPOJO o = new OrdersPOJO(
                            rs.getInt("Id"),
                            rs.getString("Item_Name"),
                            rs.getInt("Quantity"),
                            rs.getDouble("Price"),
                            rs.getString("Customer_Name"));
                    OrdersPOJO.add(o);
                }
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        return OrdersPOJO;
    }


    public ArrayList<OrdersPOJO> select(String query) {
        ArrayList<OrdersPOJO> OrdersPOJO = new ArrayList<>();

        try (Connection conn = DriverManager.getConnection(m_conn)) {

            if (conn != null) {
                String sql = query;

                Statement stmt = conn.createStatement();

                ResultSet rs = stmt.executeQuery(sql);

                while (rs.next()) {
                    OrdersPOJO o = new OrdersPOJO(
                            rs.getInt("Id"),
                            rs.getString("Item_Name"),
                            rs.getInt("Quantity"),
                            rs.getDouble("Price"),
                            rs.getString("Customer_Name"));
                    OrdersPOJO.add(o);
                }
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        return OrdersPOJO;
    }


    public OrdersPOJO getById(int id) {
        ArrayList<OrdersPOJO> results = select("SELECT * FROM Orders WHERE ID = " + id);
        if (results.size() > 0) {
            return results.get(0);
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
