package com.company;

public class Main {

    public static void main(String[] args) {




        chooseQuery();


    }

    public static void chooseQuery() {
        EmployeesDbContent dbContent = new EmployeesDbContent("jdbc:sqlite:D:\\SQLite DB\\25.03\\25.03.db");

        while (true) {
            try {
                System.out.println("Please type the number of the relevant query:");
                System.out.println("1. Select all");
                System.out.println("2. Insert");
                System.out.println("3. Update");
                System.out.println("4. Remove");
                System.out.println("5. Type your own query");
                System.out.println("6. Exit");
                int x = dbContent.s.nextInt();
                switch (x) {
                    case 1:
                        dbContent.selectAll();
                        break;
                    case 2:
                        dbContent.insertQuery();
                        break;
                    case 3:
                        dbContent.updateQuery();
                        break;
                    case 4:
                        dbContent.removeQuery();
                        break;
                    case 5:
                        System.out.println("Please type your query:");
                        String query = EmployeesDbContent.s.next();
                        dbContent.freeQuery(query);
                        break;
                    case 6:
                        return;
                }
            }
            catch (Exception e) {
                System.out.println("Incorrect Query!");
            }
        }


    }
}
