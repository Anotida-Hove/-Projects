#include "transaction.hpp"
#include <iostream>

using namespace std;

Transaction::Transaction() : type(""), amount(0.0) {}

Transaction::Transaction(const string& type, double amount)
    : type(type), amount(amount) {}

string Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}

void Transaction::displayTransaction() const {
    cout << type << ": $" << amount << endl;
}