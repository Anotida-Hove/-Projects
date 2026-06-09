#include "account.hpp"
#include <iostream>

using namespace std;

Account::Account() : accountID(0), name(""), balance(0.0) {}

Account::Account(int id, const string& name, double initialBalance)
    : accountID(id), name(name), balance(initialBalance) {}


int Account::getAccountID() const {
    return accountID;
}

string Account::getName() const {
    return name;
}

double Account::getBalance() const {
    return balance;
}

vector<Transaction> Account::getTransactions() const {
    return transactions;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
    }
}

bool Account::withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        transactions.push_back(Transaction("Withdrawal", amount));
        return true;
    }
    return false;
}

void Account::addTransaction(const Transaction& t) {
    transactions.push_back(t);
}

void Account::displayAccount() const {
    cout << "\n---------------------\n";
    cout << "Account ID: " << accountID << "\n";
    cout << "Name: " << name << "\n";
    cout << "Balance: $" << balance << "\n";
    cout << "Transactions:\n";

    if (transactions.empty()) {
        cout << "  No transactions yet.\n";
    } else {
        for (const auto& t : transactions) {
            cout << "  - " << t.getType() << ": $" << t.getAmount() << "\n";
        }
    }
    cout << "---------------------\n";
}
