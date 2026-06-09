#ifndef MANAGEMENT_HPP
#define MANAGEMENT_HPP

#include <string>

#include "account.hpp"

struct Node {
    Account account;; // The account data
    Node* next;  // Pointer to the next node

    Node(const Account& acc) {
        account = acc;
        next = nullptr;
    }

};

class AccountList {
    private:
        Node* head;  // Pointer to the first node in the list
        int size;

    public:

        AccountList(); // Constructor to initialize the empty list

        ~AccountList(); // Destructor to free memory when the list is no longer needed

        Node* gethead();

        void addAccount(const Account &acc); // Function to insert an account into the list


        bool deleteAccount(int accountID); // Function to delete an account from the list using account ID


        Account* searchAccount(int accountID);  // Function to search for an account by ID


        void showAccounts() const; // Function to display all accounts in the list
    };

#endif 

