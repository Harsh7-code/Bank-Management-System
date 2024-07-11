#include "Bank.h"
#include <iostream>
#include <string>

void displayMenu();
void handleAddAccount(Bank& bank);
void handleDeleteAccount(Bank& bank);
void handleSearchAccount(Bank& bank);
void handleListAccounts(Bank& bank);
void handleTransactions(Bank& bank);

int main() {
    Bank bank;
    char choice;

    while (true) {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
            case '1':
                handleAddAccount(bank);
                break;
            case '2':
                handleDeleteAccount(bank);
                break;
            case '3':
                handleSearchAccount(bank);
                break;
            case '4':
                handleListAccounts(bank);
                break;
            case '5':
                handleTransactions(bank);
                break;
            case '6':
                bank.saveAccountsToFile("accounts.dat");
                break;
            case '7':
                bank.loadAccountsFromFile("accounts.dat");
                break;
            case '8':
                exit(0);
            default:
                std::cout << "Invalid choice, try again." << std::endl;
        }
    }
    return 0;
}

void displayMenu() {
    std::cout << "\nBank Management System\n";
    std::cout << "1. Add Account\n";
    std::cout << "2. Delete Account\n";
    std::cout << "3. Search Account\n";
    std::cout << "4. List Accounts\n";
    std::cout << "5. Transactions\n";
    std::cout << "6. Save Accounts\n";
    std::cout << "7. Load Accounts\n";
    std::cout << "8. Exit\n";
    std::cout << "Enter your choice: ";
}

void handleAddAccount(Bank& bank) {
    std::string accountNumber, name, address, phoneNumber;
    double balance;

    std::cout << "Enter Account Number: ";
    std::cin >> accountNumber;
    std::cout << "Enter Name: ";
    std::cin >> name;
    std::cout << "Enter Address: ";
    std::cin >> address;
    std::cout << "Enter Phone Number: ";
    std::cin >> phoneNumber;
    std::cout << "Enter Initial Balance: ";
    std::cin >> balance;

    Account account(accountNumber, name, address, phoneNumber, balance);
    bank.addAccount(account);
}

void handleDeleteAccount(Bank& bank) {
    std::string accountNumber;
    std::cout << "Enter Account Number to delete: ";
    std::cin >> accountNumber;
    bank.deleteAccount(accountNumber);
}

void handleSearchAccount(Bank& bank) {
    std::string accountNumber;
    std::cout << "Enter Account Number to search: ";
    std::cin >> accountNumber;
    Account* account = bank.searchAccount(accountNumber);
    if (account) {
        std::cout << "Name: " << account->getName() << ", Address: " << account->getAddress() << ", Phone Number: " << account->getPhoneNumber() << ", Balance: " << account->getBalance() << std::endl;
    } else {
        std::cout << "Account not found." << std::endl;
    }
}

void handleListAccounts(Bank& bank) {
    bank.listAccounts();
}

void handleTransactions(Bank& bank) {
    std::string accountNumber;
    char type;
    double amount;
    std::cout << "Enter Account Number for transaction: ";
    std::cin >> accountNumber;
    Account* account = bank.searchAccount(accountNumber);
    if (account) {
        std::cout << "Enter transaction type (d for deposit, w for withdrawal): ";
        std::cin >> type;
        std::cout << "Enter amount: ";
        std::cin >> amount;
        if (type == 'd') {
            account->deposit(amount);
        } else if (type == 'w') {
            if (!account->withdraw(amount)) {
                std::cout << "Transaction failed." << std::endl;
            }
        } else {
            std::cout << "Invalid transaction type." << std::endl;
        }
        account->printTransactions();
    } else {
        std::cout << "Account not found." << std::endl;
    }
}
