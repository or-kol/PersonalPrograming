package com.example.demo;

public class HolidaysPOJO {
    public int Id;
    public String Name;
    public int Day;
    public int Month;
    public int Length;

    public HolidaysPOJO() {

    }

    public HolidaysPOJO(int id, String name, int day, int month, int length) {
        Id = id;
        this.Name = name;
        Day = day;
        Month = month;
        Length = length;
    }

    @Override
    public String toString() {
        return "HolidaysPOJO{" +
                "Id=" + Id +
                ", name='" + Name + '\'' +
                ", Day=" + Day +
                ", Month=" + Month +
                ", Length=" + Length +
                '}';
    }
}
