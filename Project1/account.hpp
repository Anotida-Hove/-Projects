#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <vector>
#include "transaction.hpp"

using namespace std;

class Account {
private:
    int accountID;
    string name;
    double balance;
    vector<Transaction> transactions;

public:
    // Constructors
    Account();
    Account(int id, const string& name, double initialBalance);

    // Getters
    int getAccountID() const;
    string getName() const;
    double getBalance() const;
    vector<Transaction> getTransactions() const;

    // Actions
    void deposit(double amount);
    bool withdraw(double amount);
    void addTransaction(const Transaction& t);

    // Display
    void displayAccount() const;
};

#endif