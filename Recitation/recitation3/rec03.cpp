/*
Name - Maddhav Suneja
rec03
Purpose: Simuilating a bank account and enabling transactions using struct and classes
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Struct for Task 1
struct AccountInfo {
    string name;
    int acc_num;
};

// Function for Task 1a
void Task1a(ifstream& ifs, vector<AccountInfo>& accounts) {
    string filename;
    ifs.open("accounts.txt");
    if (!ifs) {
        cout << "Can't open the file, try again." << endl;
    }

    string acc_name;
    int acc_no;
    while (ifs >> acc_name >> acc_no) {
        accounts.push_back({acc_name, acc_no});
    }
    ifs.close();
}

// Function for Task 1b
void Task1b(ifstream& ifs, vector<AccountInfo>& accounts) {
    accounts.clear();
    ifs.open("accounts.txt");
    string name;
    int number;
    while (ifs >> name >> number) {
        accounts.push_back({name, number});
    }
    ifs.close();
}

// Account class for Task 2
class Account {
public:
    class Transaction {
    public:
        enum Type { DEPOSIT, WITHDRAWAL };

        Transaction(Type type, int amount) : type(type), amount(amount) {}

        // Output operator for Transaction
        friend ostream& operator<<(ostream& os, const Transaction& transaction) {
            if (transaction.type == DEPOSIT) {
                os << "Deposit ";
                } else {
                    os << "Withdraw ";
                    }
                    os << transaction.amount;
                    return os;
}


    private:
        Type type;
        int amount;
    };

    Account(const string& owner, int number) : name(owner), acc_num(number), balance(0) {}

    void deposit(int amount) {
        balance += amount;
        transactions.emplace_back(Transaction::DEPOSIT, amount);
    }

    bool withdraw(int amount) {
        if (amount > balance) {
            cout << "Account# " << acc_num << " has only " << balance << ". Insufficient for withdrawal of " << amount << ".\n";
            return false;
        }
        balance -= amount;
        transactions.emplace_back(Transaction::WITHDRAWAL, amount);
        return true;
    }

    int getAccountNumber() const {
        return acc_num;
    }

    // Output operator for Account
    friend ostream& operator<<(ostream& os, const Account& account) {
        os << account.name << "\t" << account.acc_num << "\n";
        return os;
    }

    void displayDetails() const {
    cout << name << "\t" << acc_num << "\n";
    cout << "Balance: " << balance << "\n";
    cout << "Transactions:\n";
    if (transactions.empty()) {
        cout << "\n"; // Optional: indicate no transactions
    } else {
        for (const auto& transaction : transactions) {
            cout << "\t" << transaction << "\n";
        }
    }
}


private:
    string name;
    int acc_num;
    int balance;
    vector<Transaction> transactions;
};

int main() {
    ifstream ifs;
    vector<AccountInfo> accounts;

    // Task 1a
    cout << "Task1a:\nFilling vector of struct objects, define a local struct instance and set fields explicitly:\n";
    Task1a(ifs, accounts);
    for (const auto& account : accounts) {
        cout << account.name << " " << account.acc_num << endl;
    }

    // Task 1b
    cout << "Task1b:\nFilling vector of struct objects, using {} initialization:\n";
    Task1b(ifs, accounts);
    for (const auto& account : accounts) {
        cout << account.name << " " << account.acc_num << endl;
    }
    cout << "==============\n";

    // Task 2a
    cout << "Task2a:\nFilling vector of class objects, using local class object:\n";
    vector<Account> classAccounts;
    for (const auto& account : accounts) {
        classAccounts.emplace_back(account.name, account.acc_num);
        cout << classAccounts.back();
    }
    cout << endl;

    // Task 2b
    cout << "Task2b:\nOutput using output operator with getters:\n";
    for (const auto& account : classAccounts) {
        cout << account;
    }
    cout << endl;

    // Task 2c
    cout << "Task2c:\nOutput using output operator as friend without getters:\n";
    for (const auto& account : classAccounts) {
        cout << account;
    }
    cout << endl;

    // Task 2d
    cout << "Task2d:\nFilling vector of class objects, using temporary class object:\n";
    for (const auto& account : accounts) {
        Account temp(account.name, account.acc_num);
        cout << temp;
    }
    cout << endl;

    // Task 2e
    cout << "Task2e:\nFilling vector of class objects, using emplace_back:\n";
    for (const auto& account : accounts) {
        classAccounts.emplace_back(account.name, account.acc_num);
        cout << classAccounts.back();
    }
    cout << "==============\n";

    // Process transactions from a transactions file
    ifs.open("transactions.txt");
    string command;
    while (ifs >> command) {
        if (command == "Account") {
            string name;
            int number;
            ifs >> name >> number;
            classAccounts.emplace_back(name, number);
        } else if (command == "Deposit") {
            int number, amount;
            ifs >> number >> amount;
            for (auto& account : classAccounts) {
                if (account.getAccountNumber() == number) {
                    account.deposit(amount);
                    break;
                }
            }
        } else if (command == "Withdraw") {
            int number, amount;
            ifs >> number >> amount;
            for (auto& account : classAccounts) {
                if (account.getAccountNumber() == number) {
                    account.withdraw(amount);
                    break;
                }
            }
        }
    }
    ifs.close();

    // Final Account States
    cout << "\nTask 3:\nAccounts and Transaction:\n";
    int row;
    for (const auto& account : classAccounts) {
        if (row>=3) break;
        account.displayDetails();
        row++;
    }
    cout << "==============\n";

    // Task 4
    cout << "Task 4:\nTransaction nested in public section of Account:\n";
    int count = 0;
    for (const auto& account : classAccounts) {
        if (count >= 3) break; 
        account.displayDetails();
        count++;
}
    cout << "==============\n";


    return 0;
}
