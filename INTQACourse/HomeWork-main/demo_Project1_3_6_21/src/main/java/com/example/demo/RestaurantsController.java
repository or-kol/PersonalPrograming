package com.example.demo;

    import org.springframework.http.HttpHeaders;
    import org.springframework.http.HttpStatus;
    import org.springframework.http.ResponseEntity;
    import org.springframework.web.bind.annotation.*;

    import java.util.ArrayList;
    import java.util.Iterator;
    import java.util.List;

    @RestController
    public class RestaurantsController {

        private static List<RestaurantsDTO> m_Restaurants = new ArrayList<>();

        static {
            m_Restaurants.add(new RestaurantsDTO(1, "abc", "efg", "hij", 17.66));
            m_Restaurants.add(new RestaurantsDTO(2, "klm", "nop", "qrs", 33.189));
            m_Restaurants.add(new RestaurantsDTO(3, "tuv", "wxy", "zab", 199.2));
        }

        @GetMapping("/restaurant")
        public List<RestaurantsDTO> getRestaurants()
        {
            return m_Restaurants;
        }

        @GetMapping("/restaurant/{id}")
        public RestaurantsDTO getRestaurantById(@PathVariable("id") int id)
        {
            for(RestaurantsDTO r : m_Restaurants)
            {
                if (r.Id == id)
                {
                    return r;
                }
            }
            return null;
        }

        @PostMapping("/restaurant")
        public ResponseEntity<String> addRestaurant(@RequestBody RestaurantsDTO r)
        {
            m_Restaurants.add(r);
            HttpHeaders headers = new HttpHeaders();
            return new ResponseEntity<>(
                    "Custom header set", headers, HttpStatus.CREATED);
        }

        @PutMapping("/restaurant/{id}")
        public void updateRestaurant(@PathVariable("id") int id,
                                     @RequestBody RestaurantsDTO update_r)
        {
            for(RestaurantsDTO r : m_Restaurants)
            {
                if (r.Id == id)
                {
                    r.Id = update_r.Id;
                    r.Name = update_r.Name;
                    r.Address = update_r.Address;
                    r.FoodType = update_r.FoodType;
                    r.MealPrice = update_r.MealPrice;
                    return;
                }
            }
        }

        @DeleteMapping("/restaurant/{id}")
        public void delRestaurantById(@PathVariable("id") int id)
        {
            Iterator<RestaurantsDTO> iter = m_Restaurants.iterator();
            while (iter.hasNext()) {
                RestaurantsDTO c = iter.next();
                if (c.Id == id) {
                    iter.remove();
                    return;
                }
            }
        }

    }
