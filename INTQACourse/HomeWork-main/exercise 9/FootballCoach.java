package com.company;

import java.util.ArrayList;

public class FootballCoach {

    private ArrayList<String> m_activePlayers = new ArrayList<>();
    private ArrayList<String> m_benchPlayers = new ArrayList<>();
    private String m_playersFormation;


    public void sendPlayerToBench(String player) {
        if (player == null) {
            throw new InvalidPlayerException("Player input is invalid!");
        }
        else if (m_activePlayers.contains(player)) {
            m_activePlayers.remove(player);
            m_benchPlayers.add(0, player);
        }
        else {
            throw new InvalidCoachActionException("The player is not on the active players list!");
        }
    }


    public void sendPlayerToField(String player) {
        if (player == null) {
            throw new InvalidPlayerException("Player input is invalid!");
        }
        else if (m_activePlayers.size() > 11) {
            throw new NoMoreThan11PlayersException("there can't be more than 11 players in the active players list!");
        }
        else if (m_benchPlayers.contains(player)) {
            m_benchPlayers.remove(player);
            m_activePlayers.add(0, player);
        }
        else {
            throw new InvalidCoachActionException("The player is not on the bench players list!");
        }
    }


    public void changePlayersFormation(String formation) {
        if (m_activePlayers.size() < 11) {
            throw new NotEnougthPlayersException("In order to set formation there must be 11 " +
                    "players in the active players list!");
        }
        else {
            m_playersFormation = formation;
        }
    }



}
