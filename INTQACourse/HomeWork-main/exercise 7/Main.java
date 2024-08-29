package com.company;

import java.time.LocalDateTime;
import java.util.*;

public class Main {

    public static void main(String[] args) {

        //Q3
        LocalDateTime b_day = LocalDateTime.of(1988, 7, 17, 00, 00);
        ArrayList<Continent> continents = new ArrayList<>();
        continents.add(new Continent("Europe", 152456.55, 10000));
        continents.add(new Continent("Asia", 504265.17, 20000));
        continents.add(new Continent("America", 356896.89, 15000));
        continents.add(new Continent("Africa", 298255.66, 40000));

        Collections.sort(continents);
        continents.stream().forEach(System.out::println);

        System.out.println();

        //Q4
        Collections.sort(continents, new ContinentSortBySize());
        continents.stream().forEach(System.out::println);

        System.out.println();

        Collections.sort(continents, new ContinentSortByPopulation());
        continents.stream().forEach(System.out::println);

        System.out.println();

        Collections.sort(continents, new ContinentSortBySizeReverse());
        continents.stream().forEach(System.out::println);

        System.out.println();

        Collections.sort(continents, new ContinentSortByPopulationReverse());
        continents.stream().forEach(System.out::println);


        //Q11
        Stack<String> strings = new Stack<>();
        strings.push("a");
        strings.push("b");
        strings.push("c");

        strings.pop();
        strings.peek();


        //Q12
        Queue<Double> doubles = new ArrayDeque<>();
        doubles.add(1.56);
        doubles.add(1.33);
        doubles.add(1.99);

        doubles.poll();
        doubles.peek();
        doubles.clear();


        //Q21
        int x = 0;
        int y = 1;
        int z = y / x;

        try {
            int a = 0;
            int b = 1;
            int c = b / a;
        }
        catch (Exception e) {
            System.out.println("Oops...");
        }



        /*
        // SQL questions:
        CREATE TABLE PRODUCTS(
        ID INT PRIMARY KEY NOT NULL,
        NAME TEXT NOT NULL,
        PRICE REAL
        );

        INSERT INTO PRODUCTS VALUES (1, 'Abc', 123);
        INSERT INTO PRODUCTS VALUES (2, 'Def', 555);
        INSERT INTO PRODUCTS VALUES (3, 'Ghi', 89);

        SELECT *
        FROM PRODUCTS;

        DELETE FROM PRODUCTS
        WHERE ID = 2;

        UPDATE PRODUCTS
        SET PRICE = 999
        WHERE ID = 1;
         */

    }

}
