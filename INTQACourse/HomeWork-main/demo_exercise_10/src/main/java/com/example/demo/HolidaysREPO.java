package com.example.demo;

import java.sql.*;
import java.util.ArrayList;

public class HolidaysREPO {

    private String m_conn;

    public HolidaysREPO(String m_conn) {
        this.m_conn = m_conn;
    }


    public ArrayList<HolidaysPOJO> getAllHolidays() {
        ArrayList<HolidaysPOJO> HDPOJO = new ArrayList<>();

        try (Connection conn = DriverManager.getConnection(m_conn)) {

            if (conn != null) {
                String sql = "SELECT * FROM Holidays";

                Statement stmt = conn.createStatement();

                ResultSet rs = stmt.executeQuery(sql);

                while (rs.next()) {
                    HolidaysPOJO HDP = new HolidaysPOJO(
                            rs.getInt("Id"),
                            rs.getString("Name"),
                            rs.getInt("Day"),
                            rs.getInt("Month"),
                            rs.getInt("Length"));
                    HDPOJO.add(HDP);
                }
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        return HDPOJO;
    }


    public ArrayList<HolidaysPOJO> select(String query) {
        ArrayList<HolidaysPOJO> HDPOJO = new ArrayList<>();

        try (Connection conn = DriverManager.getConnection(m_conn)) {

            if (conn != null) {
                String sql = query;

                Statement stmt = conn.createStatement();

                ResultSet rs = stmt.executeQuery(sql);

                while (rs.next()) {
                    HolidaysPOJO HDP = new HolidaysPOJO(
                            rs.getInt("Id"),
                            rs.getString("Name"),
                            rs.getInt("Day"),
                            rs.getInt("Month"),
                            rs.getInt("Length"));
                    HDPOJO.add(HDP);
                }
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        return HDPOJO;
    }


    public HolidaysPOJO getById(int id) {
        ArrayList<HolidaysPOJO> results = select("SELECT * FROM Holidays WHERE ID = " + id);
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
