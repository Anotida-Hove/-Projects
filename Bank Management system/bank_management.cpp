/*main program 

instructions on how our program is working and how to compile are in README.MD*/

// Created by Anotida Hove, Genesis Hernandez, Yareli Rosales at St. Olaf College//

#include <iostream>
#include <fstream>
#include <string>
#include "management.hpp"

using namespace std;

void displayMenu() {
    cout << "\nBank Account Management Menu\n";
    cout << "1. Add Account\n";
    cout << "2. Delete Account\n";
    cout << "3. Deposit\n";
    cout << "4. Withdraw\n";
    cout << "5. Search Account\n";
    cout << "6. Display All Accounts\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}


int main( int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Error: Could not open input file " << argv[1] << "\n";
        return 1;
    }

    ofstream outputFile("output.txt"); // Output file specified in command line
    if (!outputFile) {
        cerr << "Error: Could not create output file, output.txt\n";
        return 1;
    }

    AccountList accounts;
    int id;
    string name;
    double balance;

    // Read accounts from file
    while (inputFile >> id >> name >> balance) {
        Account acc(id, name, balance);
        accounts.addAccount(acc);
    }
    inputFile.close();
    cout << "Accounts loaded from file.\n";

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter Account ID: "; cin >> id;
                cout << "Enter Name: "; cin >> name;
                cout << "Enter Initial Balance: "; cin >> balance;

                if (accounts.searchAccount(id)) {
                    cout << "Error: Account ID already exists.\n";
                } else {
                    accounts.addAccount(Account(id, name, balance));
                    cout << "Account added successfully.\n";

                }
                break;
            }
            case 2: {
                cout << "Enter Account ID to delete: "; cin >> id;
                if( accounts.deleteAccount(id)) {
                    cout << "Account deleted successfully.\n";
                } else {
                    cout << "Account ID not found.\n";
                }
                break;
            }
            case 3: {
                cout << "Enter Account ID for Deposit: "; cin >> id;
                Account* acc = accounts.searchAccount(id);
                if (acc) {
                    cout << "Enter Deposit Amount: "; 
                    cin >> balance;
                    acc->deposit(balance);
                    cout << "Deposit successful.\n";
                } else {
                    cout << "Account ID not found.\n";
                }
                break;
            }
            case 4: {
                cout << "Enter Account ID for Withdrawal: "; 
                cin >> id;
                Account* acc = accounts.searchAccount(id);
                if (acc) {
                    cout << "Enter Withdrawal Amount: "; cin >> balance;
                    if (acc->withdraw(balance)) {
                        cout << "Withdrawal successful.\n";
                    } else {
                        cout << "Insufficient balance for withdrawal.\n";
                    }
                } else { 
                    cout << "Account ID not found.\n";
                }
                break;
            }
            case 5: {
                cout << "Enter Account ID to search: "; cin >> id;
                Account* acc = accounts.searchAccount(id);
                if (acc) {
                    acc->displayAccount();
                } else {
                    cout << "Account ID not found.\n";
                }
                break;
            }
            case 6: {
                cout << "\nDisplaying all accounts:\n";
                accounts.showAccounts();
                break;
            }
            case 7: {
                cout << "Exiting the program.\n";
                break;
            }
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    // Save updated accounts to output file 
    outputFile << "================= Bank Account Management Output =================\n";
    Node* current = accounts.gethead();
    while (current != nullptr) {
        outputFile << "---------------------\n";
    outputFile << "Account ID: " << current->account.getAccountID() << "\n";
    outputFile << "Name: " << current->account.getName() << "\n";
    outputFile << "Balance: $" << current->account.getBalance() << "\n";
    outputFile << "Transactions:\n";

    if (current->account.getTransactions().empty()) {
        outputFile << "  No transactions yet.\n";
    } else {
        for (const auto& t : current->account.getTransactions()) {
            outputFile << "  - " << t.getType() << ": $" << t.getAmount() << "\n";
        }
    }

    current = current->next;
    }


    outputFile.close();
    cout << "Changes saved to output.txt\n";

    return 0;

}

