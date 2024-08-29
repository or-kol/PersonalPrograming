package com.company;

import java.util.HashMap;

public class Library {

    HashMap<String, Integer> booksMap;

    public Library(HashMap<String, Integer> booksMap) {
        this.booksMap = booksMap;
    }

    public void addNewBook(String book, Integer shelf){
        booksMap.put(book, shelf);
    }

    public Integer searchForBook(String book){
        if (booksMap.containsKey(book)) {
            return booksMap.get(book);
        }
        return -1;
    }

    public void removeBooks(String book) {
        if (booksMap.containsKey(book)) {
            booksMap.remove(book);
        }
        else {
            System.out.println("This book is not in the library");
        }
    }

    public int countBooks() {
        return booksMap.size();
    }


}
