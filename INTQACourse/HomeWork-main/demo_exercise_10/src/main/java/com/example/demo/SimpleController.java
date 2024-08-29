package com.example.demo;


import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.Random;

@RestController
public class SimpleController {

    static Random r = new Random();

    @GetMapping("/random")
    public String getRandomNumber() {
        int number = r.nextInt(1000) + 1;
        return String.format("<h2>%d</h2>", number);
    }

    @GetMapping("/multipl")
    public String multiplyNumbers(@RequestParam(value = "a", defaultValue = "0") Integer a,
                                  @RequestParam(value = "b", defaultValue = "0") Integer b) {
        return String.format("<h2>%d</h2>", a * b);
    }

    @GetMapping("/greet/{name}")
    public String greetName(@PathVariable("name") String name) {
        return String.format("<h2>Hello %s</h2>", name);
    }
}
