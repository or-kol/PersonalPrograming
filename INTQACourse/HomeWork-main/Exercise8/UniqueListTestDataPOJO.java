package com.company;

public class UniqueListTestDataPOJO {

    public int Id;
    public int Input;
    public String Result;

    public UniqueListTestDataPOJO() {

    }

    public UniqueListTestDataPOJO(int id, int input, String result) {
        Id = id;
        Input = input;
        Result = result;
    }

    @Override
    public String toString() {
        return "UniqueListTestDataPOJO{" +
                "Id=" + Id +
                ", Input=" + Input +
                ", Result=" + Result +
                '}';
    }
}
