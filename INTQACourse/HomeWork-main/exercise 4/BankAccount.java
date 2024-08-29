package com.company;

public class BankAccount {

    public String ownerName;
    public float balance;
    public int creditScore;
    public boolean isFrozen;

    public BankAccount(String ownerName, float balance, int creditScore) {
        this.ownerName = ownerName;
        this.balance = balance;
        this.creditScore = creditScore;

        if (balance > -50000) {
            isFrozen = false;
        }
        else {
            isFrozen = true;
        }
    }

    public void withdraw(float a) {
        if (isFrozen == false) {
            balance -= a;
        }
        else {
            System.out.println("the account is frozen, no withdraw is allowed");
        }
    }

    public void deposit(float a) {
        balance += a;
    }

    public void checkBalance() {
        if (balance < -10000) {
            creditScore -= 10;
        }
        else if (balance < -50000) {
            isFrozen = true;
        }
    }
}
