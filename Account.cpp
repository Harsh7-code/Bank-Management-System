#include "Account.h"
#include <iostream>
#include <sstream>

Account::Account(std::string accountNumber, std::string name, std::string address, std::string phoneNumber, double balance)
    : accountNumber(accountNumber), name(name), address(address), phoneNumber(phoneNumber), balance(balance) {}

std::string Account::getAccountNumber() const {
    return accountNumber;
}

std::string Account::getName() const {
    return name;
}

std::string Account::getAddress() const {
    return address;
}

std::string Account::getPhoneNumber() const {
    return phoneNumber;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    balance += amount;
    addTransaction("Deposit", amount);
}

bool Account::withdraw(double amount) {
    if (amount > balance) {
        std::cout << "Insufficient funds." << std::endl;
        return false;
    }
    balance -= amount;
    addTransaction("Withdrawal", amount);
    return true;
}

void Account::updateInfo(std::string name, std::string address, std::string phoneNumber) {
    this->name = name;
    this->address = address;
    this->phoneNumber = phoneNumber;
}

void Account::addTransaction(std::string type, double amount) {
    std::ostringstream oss;
    oss << type << ": " << amount << ", New Balance: " << balance;
    transactions.push_back(oss.str());
}

void Account::printTransactions() const {
    for (const auto& transaction : transactions) {
        std::cout << transaction << std::endl;
    }
}
