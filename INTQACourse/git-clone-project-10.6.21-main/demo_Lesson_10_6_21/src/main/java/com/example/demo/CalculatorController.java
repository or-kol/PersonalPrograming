package com.example.demo;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;

public class CalculatorController {

    @GetMapping("/add")
    public String add(@RequestParam(value = "a", defaultValue = "0") Integer a,
                      @RequestParam(value = "b", defaultValue = "0") Integer b)
    {
        return String.format("a: %d, b: %d, sum: %d",a, b, a+b);
    }

    @GetMapping("/mul")
    public String mul(@RequestParam(value = "a", defaultValue = "0") Integer a,
                      @RequestParam(value = "b", defaultValue = "0") Integer b)
    {
        return String.format("a: %d, b: %d, sum: %d",a, b, a*b);
    }

}
