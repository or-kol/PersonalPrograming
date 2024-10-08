package com.company;

import java.sql.*;
import java.util.ArrayList;

public class StatisticsREPO {

    private String m_conn;

    public StatisticsREPO(String m_conn) {
        this.m_conn = m_conn;
    }


    public ArrayList<StatisticsPOJO> select(String query) {
        ArrayList<StatisticsPOJO> statisticsPOJOS = new ArrayList<>();

        try (Connection conn = DriverManager.getConnection(m_conn)) {

            if (conn != null) {
                String sql = query;

                Statement stmt = conn.createStatement();

                ResultSet rs = stmt.executeQuery(sql);

                while (rs.next()) {
                    StatisticsPOJO s = new StatisticsPOJO(
                            rs.getInt("Id"),
                            rs.getInt("Floor"),
                            rs.getInt("NumberOfRestaurants"),
                            rs.getInt("NumberOfOpenLate"),
                            rs.getInt("NumberOfLargeStores"));
                    statisticsPOJOS.add(s);
                }
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        return statisticsPOJOS;
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


    public StatisticsPOJO getById(int id) {
        ArrayList<StatisticsPOJO> results =
                select("SELECT * FROM Statistic WHERE ID = " + id);
        if (results.size() > 0)
            return results.get(0);
        else
            return null;
    }






}
