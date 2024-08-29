package com.company;

import java.sql.*;
import java.util.ArrayList;

import static com.company.Main.readStoresTableAndUpdateStatisticsTable;

public class StoresREPO {

    private String m_conn;

    public StoresREPO(String m_conn) {
        this.m_conn = m_conn;
    }


    public ArrayList<StorePOJO> select(String query) {
        ArrayList<StorePOJO> storePOJOS = new ArrayList<>();

        try (Connection conn = DriverManager.getConnection(m_conn)) {

            if (conn != null) {
                String sql = query;

                Statement stmt = conn.createStatement();

                ResultSet rs = stmt.executeQuery(sql);

                while (rs.next()) {
                    StorePOJO s = new StorePOJO(
                            rs.getInt("Id"),
                            rs.getString("Name"),
                            rs.getInt("Floor"),
                            rs.getInt("IsRestaurant"),
                            rs.getInt("IsOpenLate"),
                            rs.getInt("IsLarge"));
                    storePOJOS.add(s);
                }
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        return storePOJOS;
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

        readStoresTableAndUpdateStatisticsTable();
    }


    public StorePOJO getById(int id) {
        ArrayList<StorePOJO> results =
                select("SELECT * FROM Stores WHERE ID = " + id);
        if (results.size() > 0)
            return results.get(0);
        else
            return null;
    }




}
