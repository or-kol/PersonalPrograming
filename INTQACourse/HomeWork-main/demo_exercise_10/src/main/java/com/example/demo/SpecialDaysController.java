package com.example.demo;

import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
public class SpecialDaysController {

    private static SpecialDaysREPO SDR = new SpecialDaysREPO("jdbc:sqlite:D:\\SQLiteDB\\Exercise_10_calendar\\Calendar.db");

    @GetMapping("/SpecialDay")
    public List<SpecialDaysPOJO> getSpecialDays()
    {
        return SDR.getAllSpecialDays();
    }


    @GetMapping("/SpecialDay/{id}")
    public SpecialDaysPOJO getSpecialDayById(@PathVariable("id") int id) {
        return SDR.getById(id);
    }

    @PostMapping("/SpecialDay")
    public String addSpecialDay(@RequestBody SpecialDaysPOJO SDP)
    {
        SDR.update(String.format(
                "INSERT INTO Special_Days (Name, Day, Month) VALUES ('%s', %d, %d)",
                SDP.Name, SDP.Day, SDP.Month));
        return "Special Day added";
    }

    @PutMapping("/SpecialDay/{id}")
    public String updateSpecialDay(@PathVariable("id") int id, @RequestBody SpecialDaysPOJO update) {
        SDR.update(String.format(
                "UPDATE Special_Days set Name = '%s', Day = %d, Month = %d WHERE id = %d",
                update.Name, update.Day, update.Month, id));
        return "Special Day updated";
    }

    @DeleteMapping("/SpecialDay/{id}")
    public String deleteSpecialDay(@PathVariable("id") int id) {
        SDR.update(String.format("DELETE FROM Special_Days WHERE ID = %d", id));
        return "Special Day deleted";
    }


}
