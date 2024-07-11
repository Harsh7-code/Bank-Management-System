#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

class Account {
public:
    Account(std::string accountNumber, std::string name, std::string address, std::string phoneNumber, double balance);
    
    std::string getAccountNumber() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getPhoneNumber() const;
    double getBalance() const;

    void deposit(double amount);
    bool withdraw(double amount);
    void updateInfo(std::string name, std::string address, std::string phoneNumber);

    void addTransaction(std::string type, double amount);
    void printTransactions() const;

private:
    std::string accountNumber;
    std::string name;
    std::string address;
    std::string phoneNumber;
    double balance;
    std::vector<std::string> transactions;
};

#endif // ACCOUNT_H
