package com.company;

import java.util.*;

public class Main {

    public static void main(String[] args) {

        ArrayList<String> carsList = new ArrayList<>();
        carsList.add("Picanto");
        carsList.add("Rio");
        carsList.add("Fortte");
        carsList.add("Sportage");
        carsList.add("Optima");

        Stack<String> workersList = new Stack<>();
        workersList.add("a");
        workersList.add("b");
        workersList.add("c");
        workersList.add("d");
        workersList.add("e");

        Queue<String> customersList = new ArrayDeque<>();
        customersList.add("v");
        customersList.add("w");
        customersList.add("x");
        customersList.add("y");
        customersList.add("z");

        HashMap<String, Float> carFeeList = new HashMap();
        carFeeList.put("Picanto", 15f);
        carFeeList.put("Rio", 20f);
        carFeeList.put("Fortte", 25f);
        carFeeList.put("Sportage", 30f);
        carFeeList.put("Optima", 35f);

        CarsRentalAgency cra = new CarsRentalAgency(carsList, workersList, customersList, carFeeList);

        cra.rentACar();
        cra.returnACar("G", "H");


        readStoresTableAndUpdateStatisticsTable();


    }



    public static void readStoresTableAndUpdateStatisticsTable(){
        StoresREPO storesREPO = new StoresREPO("jdbc:sqlite:D:\\SQLiteDB\\Exercise8\\Exercise8_Mall.db");
        StatisticsREPO statisticsREPO = new StatisticsREPO("jdbc:sqlite:D:\\SQLiteDB\\Exercise8\\Exercise8_Mall.db");

        statisticsREPO.update("DELETE FROM Statistics WHERE Id > 0");

        for (int i1 = 1; i1 <= 4; i1++) {
            ArrayList<StorePOJO> stores = storesREPO.select("SELECT * FROM Stores WHERE Floor = " + i1);
            int countNumOfRestaurants = 0;
            int countNumOpenLate = 0;
            int countNumOfLarge = 0;
            for (int i2 = 0; i2 < stores.size(); i2++) {
                countNumOfRestaurants += stores.get(i2).IsRestaurant;

                countNumOpenLate += stores.get(i2).IsOpenLate;

                countNumOfLarge += stores.get(i2).IsLarge;
            }
            statisticsREPO.update(String.format("INSERT INTO Statistics (Floor, NumberOfRestaurants, NumberOfOpenLate, NumberOfLargeStores) " +
                    "Values (%d, %d, %d, %d)", i1, countNumOfRestaurants, countNumOpenLate, countNumOfLarge));
        }
    }

}
