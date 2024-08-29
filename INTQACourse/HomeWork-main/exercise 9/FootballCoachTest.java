package com.company;

import org.junit.Test;

import java.lang.reflect.Field;
import java.util.ArrayList;

import static junit.framework.TestCase.assertEquals;

public class FootballCoachTest {

    private ArrayList<String> get_activePlayersList(FootballCoach fc) {
        try {
            ArrayList<String> fieldValue = null;
            Field privateStringField = null;
            privateStringField = FootballCoach.class.getDeclaredField("m_activePlayers");
            privateStringField.setAccessible(true);
            fieldValue = (ArrayList<String>)privateStringField.get(fc);

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

    private ArrayList<String> get_benchPlayersList(FootballCoach fc) {
        try {
            ArrayList<String> fieldValue = null;
            Field privateStringField = null;
            privateStringField = FootballCoach.class.getDeclaredField("m_benchPlayers");
            privateStringField.setAccessible(true);
            fieldValue = (ArrayList<String>)privateStringField.get(fc);

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

    private String get_playersFormation(FootballCoach fc) {
        try {
            String fieldValue = null;
            Field privateStringField = null;
            privateStringField = FootballCoach.class.getDeclaredField("m_playersFormation");
            privateStringField.setAccessible(true);
            fieldValue = (String)privateStringField.get(fc);

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




    @Test
    public void test_FootballCoach_sendPlayerToField_pos1(){
        FootballCoach fc = new FootballCoach();
        ArrayList <String> benchList = get_benchPlayersList(fc);
        benchList.add("David");


        fc.sendPlayerToField("David");


        ArrayList<String> activeList = get_activePlayersList(fc);

        assertEquals(1, activeList.size());
        assertEquals ("David", activeList.get(0));
    }

    @Test
    public void test_FootballCoach_sendPlayerToField_pos2(){
        FootballCoach fc = new FootballCoach();
        ArrayList <String> benchList = get_benchPlayersList(fc);
        benchList.add("David");
        benchList.add("James");


        fc.sendPlayerToField("David");
        fc.sendPlayerToField("James");


        ArrayList<String> activeList = get_activePlayersList(fc);

        assertEquals(2, activeList.size());
        assertEquals ("James", activeList.get(0));
    }

    @Test (expected = InvalidPlayerException.class)
    public void test_FootballCoach_sendPlayerToField_neg1(){
        FootballCoach fc = new FootballCoach();
        fc.sendPlayerToField(null);
    }

    @Test (expected = NoMoreThan11PlayersException.class)
    public void test_FootballCoach_sendPlayerToField_neg2(){
        FootballCoach fc = new FootballCoach();

        ArrayList <String> benchList = get_benchPlayersList(fc);
        benchList.add("David");
        for (int i = 0; i < 20; i++) {
            benchList.add("David");
        }

        for (int i = 0; i < 20; i++) {
            fc.sendPlayerToField("David");
        }
    }



    @Test
    public void test_FootballCoach_sendPlayerToBench_pos1(){
        FootballCoach fc = new FootballCoach();
        ArrayList<String> activeList = get_activePlayersList(fc);
        activeList.add("David");

        fc.sendPlayerToBench("David");

        ArrayList <String> benchList = get_benchPlayersList(fc);

        assertEquals(1, benchList.size());
        assertEquals ("David", benchList.get(0));
    }

    @Test
    public void test_FootballCoach_sendPlayerToBench_pos2(){
        FootballCoach fc = new FootballCoach();

        ArrayList<String> activeList = get_activePlayersList(fc);
        activeList.add("David");
        activeList.add("James");

        fc.sendPlayerToBench("David");
        fc.sendPlayerToBench("James");

        ArrayList <String> benchList = get_benchPlayersList(fc);

        assertEquals(2, benchList.size());
        assertEquals ("James", benchList.get(0));
    }

    @Test (expected = InvalidPlayerException.class)
    public void test_FootballCoach_sendPlayerToBench_neg1(){
        FootballCoach fc = new FootballCoach();
        fc.sendPlayerToBench(null);
    }

    @Test (expected = InvalidCoachActionException.class)
    public void test_FootballCoach_sendPlayerToBench_neg2(){
        FootballCoach fc = new FootballCoach();
        fc.sendPlayerToBench("null");
    }



    @Test
    public void test_FootballCoach_changePlayersFormation_pos1(){
        FootballCoach fc = new FootballCoach();
        ArrayList<String> activeList = get_activePlayersList(fc);
        for (int i = 0; i <= 10; i++) {
            activeList.add("David");
        }

        fc.changePlayersFormation("4-4-2");

        String formation = get_playersFormation(fc);

        assertEquals ("4-4-2", formation);
    }


    @Test (expected = NotEnougthPlayersException.class)
    public void test_FootballCoach_changePlayersFormation_neg1(){
        FootballCoach fc = new FootballCoach();
        ArrayList<String> activeList = get_activePlayersList(fc);
        for (int i = 0; i <= 9; i++) {
            activeList.add("David");
        }

        fc.changePlayersFormation("4-4-2");
    }




}
