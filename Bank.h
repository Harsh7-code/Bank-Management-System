#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include <vector>

class Bank {
public:
    void addAccount(Account account);
    void deleteAccount(std::string accountNumber);
    Account* searchAccount(std::string accountNumber);
    void listAccounts() const;
    void saveAccountsToFile(const std::string& filename) const;
    void loadAccountsFromFile(const std::string& filename);

private:
    std::vector<Account> accounts;
};

#endif // BANK_H
