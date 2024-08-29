package com.company;

public class FootballTeam {

    public String name;
    public String country;
    public String[] playersList = new String[11];
    public int grade;


    public void changeRating(int a) {
        grade = a;
    }

    public void replacePlayer(String fn_arr[], String b, String c) {
        for (int i = 0; i < fn_arr.length; i++) {
            if (fn_arr[i].equals(b)) {
                fn_arr[i] = c;
                break;
            }
        }

    }



}
