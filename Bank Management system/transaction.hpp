#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <string>

using namespace std;

class Transaction {
private:
    string type; // "Deposit" or "Withdrawal"
    double amount;

public:
    // Constructors
    Transaction();
    Transaction(const string& type, double amount);

    // Getters
    string getType() const;
    double getAmount() const;

    // Display
    void displayTransaction() const;
};

#endif