package com.example.demo;

import java.sql.*;
import java.util.ArrayList;

public class SpecialDaysREPO {

    private String m_conn;

    public SpecialDaysREPO(String m_conn) {
        this.m_conn = m_conn;
    }


    public ArrayList<SpecialDaysPOJO> getAllSpecialDays() {
        ArrayList<SpecialDaysPOJO> SDPOJO = new ArrayList<>();

        try (Connection conn = DriverManager.getConnection(m_conn)) {

            if (conn != null) {
                String sql = "SELECT * FROM Special_Days";

                Statement stmt = conn.createStatement();

                ResultSet rs = stmt.executeQuery(sql);

                while (rs.next()) {
                    SpecialDaysPOJO SDP = new SpecialDaysPOJO(
                            rs.getInt("Id"),
                            rs.getString("Name"),
                            rs.getInt("Day"),
                            rs.getInt("Month"));
                    SDPOJO.add(SDP);
                }
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        return SDPOJO;
    }


    public ArrayList<SpecialDaysPOJO> select(String query) {
        ArrayList<SpecialDaysPOJO> SDPOJO = new ArrayList<>();

        try (Connection conn = DriverManager.getConnection(m_conn)) {

            if (conn != null) {
                String sql = query;

                Statement stmt = conn.createStatement();

                ResultSet rs = stmt.executeQuery(sql);

                while (rs.next()) {
                    SpecialDaysPOJO SDP = new SpecialDaysPOJO(
                            rs.getInt("Id"),
                            rs.getString("Name"),
                            rs.getInt("Day"),
                            rs.getInt("Month"));
                    SDPOJO.add(SDP);
                }
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        return SDPOJO;
    }


    public SpecialDaysPOJO getById(int id) {
        ArrayList<SpecialDaysPOJO> results = select("SELECT * FROM Special_Days WHERE ID = " + id);
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
