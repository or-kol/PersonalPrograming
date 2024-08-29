package com.company;

import java.sql.*;
import java.util.Scanner;

public class EmployeesDbContent {

    public static Scanner s = new Scanner(System.in);

    private static String m_conn;

    public EmployeesDbContent(String m_conn) {
        this.m_conn = m_conn;
    }

    public static void selectAll() {
        System.out.println("please input table name:");
        String table_name = s.next();
        try (Connection conn = DriverManager.getConnection(m_conn)) {
            if (conn != null) {
                String sql = "SELECT * FROM " + table_name;

                Statement stmt = conn.createStatement();
                ResultSet rs = stmt.executeQuery(sql);
                // loop through the result set
                while (rs.next()) {
                    System.out.println(rs.getInt("id") + "\t" +
                            rs.getString("name") + "\t" +
                            rs.getDouble("salary"));
                }
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }


    public static void insertQuery() {
        System.out.println("Please insert table name:");
        String table_name = s.next();
        System.out.println("Please insert columns names:");
        String columns_names = s.next();
        System.out.println("Please insert data for each column:");
        String data = s.next();
        try (Connection conn = DriverManager.getConnection(m_conn)) {
            if (conn != null) {
                String sql = "INSERT INTO " + table_name + " (" + columns_names + ") VALUES (" + data + ")";

                Statement stmt = conn.createStatement();
                ResultSet rs = stmt.executeQuery(sql);
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }


    public static void updateQuery() {
        System.out.println("Please insert table name:");
        String table_name = s.next();
        System.out.println("Please insert column name:");
        String column_name = s.next();
        System.out.println("Please insert > / < / = / LIKE:");
        String mark = s.next();
        System.out.println(String.format("Please insert %s data:", column_name));
        String column_data = s.next();
        System.out.println("Please insert ID of the record:");
        int data = s.nextInt();
        try (Connection conn = DriverManager.getConnection(m_conn)) {
            if (conn != null) {
                String sql = "UPDATE " + table_name + " SET " + column_name + " " + mark + " " + column_data + " where ID = " + data;

                Statement stmt = conn.createStatement();
                stmt.executeUpdate(sql);
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    public static void removeQuery() {
        System.out.println("Please insert table name:");
        String table_name = s.next();
        System.out.println("Please insert column name:");
        String column_name = s.next();
        System.out.println("Please insert > / < / = / LIKE:");
        String mark = s.next();
        System.out.println(String.format("Please insert %s data:", column_name));
        String column_data = s.next();
        try (Connection conn = DriverManager.getConnection(m_conn)) {
            if (conn != null) {
                String sql = "DELETE FROM " + table_name + " WHERE " + column_name + " " + mark + " " + column_data;

                Statement stmt = conn.createStatement();
                ResultSet rs = stmt.executeQuery(sql);
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }


    public static void freeQuery(String query) {
        try (Connection conn = DriverManager.getConnection(m_conn)) {
            if (conn != null) {
                String sql = query;

                Statement stmt = conn.createStatement();
                ResultSet rs = stmt.executeQuery(sql);
                // loop through the result set
                while (rs.next()) {
                    System.out.println(rs.getInt("id") + "\t" +
                            rs.getString("name") + "\t" +
                            rs.getDouble("salary"));
                }
            }
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }
}