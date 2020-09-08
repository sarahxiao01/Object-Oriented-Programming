//
//  main.cpp
//  rec03
//
//  Created by Sarah Xiao on 2/14/20.
//  Copyright © 2020 Sarah Xiao. All rights reserved.
//
// Provided
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
//
// Task 1: The Account struct. Call it AccountS
//
struct AccountS {
    string accName;
    int accNumber;
};
//
// Task 2: The Account class. Call it AccountC
//
class AccountC {
    friend ostream& operator<<(ostream&os, const AccountC& myAcc);
public:
    AccountC (const string& name, int number) : accName(name), accNumber(num) {};
    string getName() const{
        return accName;
    }
    int getNumber() const{
        return accNumber;
    }
    void deposit(int money) {
        balance += money;
        Acchistory.push_back(Transaction(1, money));
    }
    void withdrawl(int money) {
        if (balance - money < 0){
            cerr << "insufficient balance" << endl;
        }
        else {
            balance -= money;
            Acchistory.push_back(Transaction(0, money));
        }
    }
private:
        class Transaction {
            friend ostream& operator<<(ostream& os, const AccountC& myAcc);
        public:
            //Transaction () {};
            Transaction (int isDeposit, int amount) : isDeposit(isDeposit), amount(amount) {};
        private:
            int isDeposit;
            int amount;
        };
    string accName;
    int accNumber;
    vector<Transaction> acchistory;
    int balance = 0;
};

ostream& operator<<(ostream& os, const AccountC& myAcc){
    os << myAcc.accName << ":" << myAcc.accNumber << endl;
    os << "Transaction History:" << endl;
    for(const AccountC::Transaction& myTransaction: myAcc.Acchistory){
        os << myTransaction.isDeposit << " " << myTransaction.amount << endl; ;
    }
    return os;
}
//
// Task 3
//
//
// Task 4
//
// Transaction class definition with embedded Account class
int main() {
    //
    // Task 1: account as struct
    //
    //      1a. Filling vector of account structs from the file
    cout << "Task1a:\n";
    cout << "Filling vector of struct objects, define a local struct instance "
         << " and set fields explicitly:\n";
    ifstream ifs("accounts.txt");
    vector<AccountS> vectorofAccS;
    string name;
    int number;
    if(!ifs){
        cerr << "Could not open the file" << endl;
        exit(1);
    }
    while(ifs >> name >> number) {
        AccountS myAccS;
        myAccS.accName = name;
        myAccS.accNumber = number;
        vectorofAccS.push_back(myAccS);
    }
    ifs.close();
    for(const AccountS& myAccS : vectorofAccS){
        cout << myAccS.accName << ": " << myAccS.accNumber << endl;
    }
    cout << endl;
    //      1b
    cout << "Task1b:\n";
    cout << "Filling vector of struct objects, using {} initialization:\n"
    vectorofAccS.clear();   //to clear the file
    ifs.open("accounts.txt");
    if(!ifs){
        cerr << "Could not open the file" << endl;
        exit(1);
    }
    while(ifs >> name >> number) {
        AccountS myAccS {name, number};
        vectorofAccS.push_back(myAccS);
    }
    ifs.close();
    for(const AccountS& myAccS : vectorofAccS){
        cout << myAccS.accName << ": " << myAccS.accNumber << endl;
    }
    cout << endl;
    //==================================
    //
    // Task 2: account as class
    //
    //      2a
    cout << "==============\n";
    cout << "\nTask2a:";
    cout << "\nFilling vector of class objects, using local class object:\n";
    vector<AccountC> vectorofAccC;
    ifs.open("accounts.txt");
    while(ifs >> name >> number){
        AccountC myAcc = AccountC(name, number);
        vectorofAccC.push_back(myAcc);
    }
    ifs.close();
    cout << "---\n";
    cout << "\nTask2b:\n";
    cout << "output using output operator with getters\n";
    for(const AccountC& myAcc : vectorofAccC){
        cout << myAcc << endl;
    }
    cout << "\nTask2c:\n";
    cout << "output using output operator as friend without getters\n";
    // Note code here will be same as above.
    for(const AccountC& myAcc : vectorofAccC){
        cout << myAcc << endl;
    }
    cout << "\nTask2d:\n";
    cout << "Filling vector of class objects, using temporary class object:\n";
    vectorofAccC.clear();
    ifs.open("accounts.txt");
    while(ifs >> name >> number){
        vectorofAccC.push_back(AccountC(name, number));
    }
    ifs.close();
    for(const AccountC& myAcc : vectorofAccC){
        cout << myAcc << endl;
    }
    cout << "\nTask2e:\n";
    cout << "\nFilling vector of class objects, using emplace_back:\n";
    vectorofAccC.clear();
    ifs.open("accounts.txt");
    while(ifs >> name >> number){
        vectorofAccC.emplace_back(name, number);
    }
    ifs.close();
    for(const AccountC& myAcc : vectorofAccC){
        cout << myAcc << endl;
    }
    // Task 3
    cout << "==============\n"
    cout << "\nTask 3:\n\nAccounts and Transaction:\n";

    // Task 4
    cout << "==============\n";
    cout << "\nTask 4:\n\nAccounts and Transaction:\n"
         << "Account class is nested inside Transaction class.\n";
    ifs.open("transactions.txt");
    if (!ifs) {
        cerr << "could not open the file";
        exit(1);
    }
    string command;
    string myname;
    int mynum;
    int money;
    while(ifs >> command){
        if(command == "Account"){
            ifs >> myname;
            ifs >> mynum;
        }
        else if(command == "Withdraw"){
            ifs >> mynum;
            for(AccountC& myAccC : vectorofAccC){
                if(myAccC.getNumber()==mynum){
                    ifs >> money;
                    myAccC.withdrawl(money);
                    break;
                }
            }
        }
        else if(command == "Deposit"){
            ifs >> mynum;
            for(AccountC& myAccC : vectorofAccC){
                if(myAccountC.getNumber() == mynum){
                    ifs >> money;
                    myAccC.deposit(money);
                    break;
                }
            }
        }
    }
    ifs.close();
    for(const AccountC& myAcc : vectorofAccC){
        cout << myAcc << endl;
    }
}
