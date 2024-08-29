package com.example.demo;

import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
public class HolidaysController {

    private static HolidaysREPO HDR = new HolidaysREPO("jdbc:sqlite:D:\\SQLiteDB\\Exercise_10_calendar\\Calendar.db");

    @GetMapping("/Holiday")
    public List<HolidaysPOJO> getHolidays()
    {
        return HDR.getAllHolidays();
    }


    @GetMapping("/Holiday/{id}")
    public HolidaysPOJO getHolidayById(@PathVariable("id") int id) {
        return HDR.getById(id);
    }

    @PostMapping("/Holiday")
    public String addHoliday(@RequestBody HolidaysPOJO HDP)
    {
        HDR.update(String.format(
                "INSERT INTO Holidays (Name, Day, Month, Length) VALUES ('%s', %d, %d, %d)",
                HDP.Name, HDP.Day, HDP.Month, HDP.Length));
        return "Holiday added";
    }

    @PutMapping("/Holiday/{id}")
    public String updateHoliday(@PathVariable("id") int id, @RequestBody HolidaysPOJO update) {
        HDR.update(String.format(
                "UPDATE Holidays set Name = '%s', Day = %d, Month = %d, Length = %d WHERE id = %d",
                update.Name, update.Day, update.Month, update.Length, id));
        return "Holiday updated";
    }

    @DeleteMapping("/Holiday/{id}")
    public String deleteHoliday(@PathVariable("id") int id) {
        HDR.update(String.format("DELETE FROM Holidays WHERE ID = %d", id));
        return "Holiday deleted";
    }
}
