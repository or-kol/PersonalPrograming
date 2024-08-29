package com.example.demo;


import java.sql.*;
import java.util.ArrayList;

public class CalculatorREPO {

    private String m_conn;

    public CalculatorREPO(String m_conn) {
        this.m_conn = m_conn;
    }


    public ArrayList<CalculatorPOJO> getAllCalculator() {
        ArrayList<CalculatorPOJO> calcPOJO = new ArrayList<>();

        try (Connection conn = DriverManager.getConnection(m_conn)) {

            if (conn != null) {
                String sql = "SELECT * FROM CALCULATOR";

                Statement stmt = conn.createStatement();

                ResultSet rs = stmt.executeQuery(sql);

                while (rs.next()) {
                    CalculatorPOJO c = new CalculatorPOJO(
                            rs.getInt("id"),
                            rs.getDouble("input1"),
                            rs.getDouble("input2"),
                            rs.getDouble("result"),
                            rs.getString("method"));
                    calcPOJO.add(c);
                }
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        return calcPOJO;
    }

    public ArrayList<CalculatorPOJO> select(String query) {
        ArrayList<CalculatorPOJO> calcPOJO = new ArrayList<>();

        try (Connection conn = DriverManager.getConnection(m_conn)) {

            if (conn != null) {
                String sql = query;

                Statement stmt = conn.createStatement();

                ResultSet rs = stmt.executeQuery(sql);

                while (rs.next()) {
                    CalculatorPOJO c = new CalculatorPOJO(
                            rs.getInt("id"),
                            rs.getDouble("input1"),
                            rs.getDouble("input2"),
                            rs.getDouble("result"),
                            rs.getString("method"));
                    calcPOJO.add(c);
                }
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        return calcPOJO;
    }


    public void update(String query) {
        try (Connection conn = DriverManager.getConnection(m_conn)) {

            if (conn != null) {
                String sql = query;

                Statement stmt = conn.createStatement();

                int result = stmt.executeUpdate(sql); // not expect result
                System.out.println(result + " record updated.");
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }



    public CalculatorPOJO getById(int id) {
        ArrayList<CalculatorPOJO> results =
                select("SELECT * FROM CALCULATOR WHERE ID = " + id);
        if (results.size() > 0)
            return results.get(0);
        else
            return null;
    }
}
