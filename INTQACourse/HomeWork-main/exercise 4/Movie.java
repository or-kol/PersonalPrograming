package com.company;

import java.util.Date;

public class Movie {

    public String name;
    public Date datePublished;
    public float grade;
    public String genre;

    public static int movieCounter = 0;
    public static final int ratingForOscar = 9;

    public Movie(String name, float grade, String genre) {
        this.name = name;
        this.datePublished = new Date();
        this.grade = grade;
        this.genre = genre;

        movieCounter++;
    }

    @Override
    public String toString() {
        return "Movie{" +
                "name='" + name + '\'' +
                ", datePublished=" + datePublished +
                ", grade=" + grade +
                ", genre='" + genre + '\'' +
                '}';
    }


    public static void resetCounter() {
        movieCounter = 0;
    }

    public boolean isWonOscar() {
        return grade > ratingForOscar;
    }
}
