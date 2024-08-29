package com.company;

import java.lang.reflect.Field;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        try {
            countChar(null); //NullPointerException
        }
        catch (NullPointerException ex){
            System.out.println(ex);
        }

        Person person = new Person("David");
        String personName = get_PersonName(person);
        System.out.println(personName);

    }


    public static int countChar(String string){
        return string.length();
    }


    public static String get_PersonName(Person person) {
        try {
            String fieldValue = null;
            Field privateStringField = null;
            privateStringField = Person.class.getDeclaredField("m_name");
            privateStringField.setAccessible(true);
            fieldValue = (String)privateStringField.get(person);

            return fieldValue;
        }
        catch (NoSuchFieldException ex)
        {
            ex.printStackTrace();
        }
        catch (IllegalAccessException ex) {
            ex.printStackTrace();
        }

        return null;
    }

}
