#include "management.hpp"
#include "account.hpp"
#include "transaction.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

AccountList::AccountList(){
    head = nullptr;
    size = 0;
}

AccountList::~AccountList() { // Destructor to delete all nodes in the list
    Node* current = head;
    
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;
    size = 0;
}

Node* AccountList::gethead(){
    return head;
}

void AccountList::addAccount(const Account &acc) {  // Insert an account into the list
    
    Node* newNode = new Node(acc);  // Create a new node for the account

    newNode->next = head;  // New node points to the previous first node

    head = newNode;  // Head now points to the new node
}


bool AccountList::deleteAccount(int accountID) { // Delete an account by its account ID
    
    Node* current = head;

    Node* previous = nullptr;

    // Find the account in the list
    while (current != nullptr && current->account.getAccountID() != accountID) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {  // If the Account can't be found
        return false;
    }

    // If account is the first node
    if (previous == nullptr) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    delete current;  // Free memory

    return true;
}

Account* AccountList::searchAccount(int accountID) {
    
    Node* current = head;
    while (current != nullptr) {
        if (current->account.getAccountID() == accountID) {
            return &current->account;  // Return pointer to the account if found
        }
        current = current->next;
    }
    return nullptr;  // Return nullptr if not found
}

void AccountList::showAccounts() const {
    Node* current = head;
    while (current != nullptr) {
        cout << "ID: " << current->account.getAccountID()
             << ", Name: " << current->account.getName()
             << ", Balance: $" << current->account.getBalance() << "\n";
        current = current->next;
    }
}