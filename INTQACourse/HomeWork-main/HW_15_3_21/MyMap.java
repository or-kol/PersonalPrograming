package com.company;


import java.util.Collection;
import java.util.HashMap;
import java.util.Set;

public class MyMap {

    public void put(Integer key, Person p, HashMap<Integer, Person> map) {
        map.put(key, p);
    }

    public Person get(Integer key, HashMap<Integer, Person> map){
        return map.get(key);
    }

    public boolean containKey(Integer key, HashMap<Integer, Person> map){
        return map.containsKey(key);
    }

    public Set<Integer> getKeys(HashMap<Integer, Person> map){
        return map.keySet();
    }

    public Collection<Person> getValues(HashMap<Integer, Person> map) {
        return map.values();
    }

    public void clear(HashMap<Integer, Person> map){
        map.clear();
    }

    public int count(HashMap<Integer, Person> map){
        return map.size();
    }

}
