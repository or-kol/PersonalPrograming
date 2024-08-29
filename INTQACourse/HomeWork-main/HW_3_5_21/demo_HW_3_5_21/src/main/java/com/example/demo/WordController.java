package com.example.demo;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController

public class WordController {
    @GetMapping("/counter")
    public String countCharacters(@RequestParam(value = "word", defaultValue = "null") String word) {
        return String.format("the word %s has %d characters!", word, word.length());
    }

    @GetMapping("/concat")
    public String concat(@RequestParam(value = "word1", defaultValue = "null") String word1,
                         @RequestParam(value = "word2", defaultValue = "null") String word2) {
        return String.format("<u>%s %s</u>", word1, word2);
    }

    }
