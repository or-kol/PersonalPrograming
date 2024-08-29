package com.company;

import java.sql.*;
import java.util.ArrayList;

public class UniqueListTestDataREPO {

    private String m_conn;

    public UniqueListTestDataREPO(String m_conn) {
        this.m_conn = m_conn;
    }


    public ArrayList<UniqueListTestDataPOJO> select(String query) {
        ArrayList<UniqueListTestDataPOJO> unqLstPOJO = new ArrayList<>();

        try (Connection conn = DriverManager.getConnection(m_conn)) {

            if (conn != null) {
                String sql = query;

                Statement stmt = conn.createStatement();

                ResultSet rs = stmt.executeQuery(sql);

                while (rs.next()) {
                    UniqueListTestDataPOJO c = new UniqueListTestDataPOJO(
                            rs.getInt("Id"),
                            rs.getInt("Input"),
                            rs.getString("Result"));
                    unqLstPOJO.add(c);
                }
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        return unqLstPOJO;
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


    public ArrayList<UniqueListTestDataPOJO> getAllCalculators() {
        ArrayList<UniqueListTestDataPOJO> unqLstPOJO = new ArrayList<>();

        try (Connection conn = DriverManager.getConnection(m_conn)) {

            if (conn != null) {
                String sql = "SELECT * FROM CALCULATOR";

                Statement stmt = conn.createStatement();

                ResultSet rs = stmt.executeQuery(sql);

                while (rs.next()) {
                    UniqueListTestDataPOJO c = new UniqueListTestDataPOJO(
                            rs.getInt("Id"),
                            rs.getInt("Input"),
                            rs.getString("Result"));
                    unqLstPOJO.add(c);
                }
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        return unqLstPOJO;
    }


    public UniqueListTestDataPOJO getById(int id) {
        ArrayList<UniqueListTestDataPOJO> results =
                select("SELECT * FROM CALCULATOR WHERE ID = " + id);
        if (results.size() > 0)
            return results.get(0);
        else
            return null;
    }
}
