#include "Bank.h"
#include <iostream>
#include <fstream>

void Bank::addAccount(Account account) {
    accounts.push_back(account);
}

void Bank::deleteAccount(std::string accountNumber) {
    accounts.erase(std::remove_if(accounts.begin(), accounts.end(), [&](const Account& acc) {
        return acc.getAccountNumber() == accountNumber;
    }), accounts.end());
}

Account* Bank::searchAccount(std::string accountNumber) {
    for (auto& account : accounts) {
        if (account.getAccountNumber() == accountNumber) {
            return &account;
        }
    }
    return nullptr;
}

void Bank::listAccounts() const {
    for (const auto& account : accounts) {
        std::cout << "Account Number: " << account.getAccountNumber() << ", Name: " << account.getName() << ", Balance: " << account.getBalance() << std::endl;
    }
}

void Bank::saveAccountsToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    for (const auto& account : accounts) {
        file.write(reinterpret_cast<const char*>(&account), sizeof(Account));
    }
}

void Bank::loadAccountsFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    Account account;
    while (file.read(reinterpret_cast<char*>(&account), sizeof(Account))) {
        accounts.push_back(account);
    }
}
