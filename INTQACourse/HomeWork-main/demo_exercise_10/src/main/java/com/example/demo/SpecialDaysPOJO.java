package com.example.demo;

public class SpecialDaysPOJO {
    public int Id;
    public String Name;
    public int Day;
    public int Month;

    public SpecialDaysPOJO() {

    }

    public SpecialDaysPOJO(int id, String name, int day, int month) {
        Id = id;
        Name = name;
        Day = day;
        Month = month;
    }

    @Override
    public String toString() {
        return "SpecialDaysPOJO{" +
                "Id=" + Id +
                ", Name='" + Name + '\'' +
                ", Day=" + Day +
                ", Month=" + Month +
                '}';
    }
}
