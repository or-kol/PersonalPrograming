package com.example.demo;

public class CalculatorPOJO {
    public int Id;
    public double Input1;
    public double Input2;
    public double Result;
    public String Method;

    public CalculatorPOJO() {

    }

    public CalculatorPOJO(int id, double input1, double input2, double result, String method) {
        Id = id;
        Input1 = input1;
        Input2 = input2;
        Result = result;
        Method = method;
    }

    @Override
    public String toString() {
        return "CalculatorPOJO{" +
                "Id=" + Id +
                ", Input1=" + Input1 +
                ", Input2=" + Input2 +
                ", Result=" + Result +
                ", Method='" + Method + '\'' +
                '}';
    }
}
