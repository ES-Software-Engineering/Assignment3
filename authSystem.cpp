//
// Created by 김성민 on 2023/05/21.
//

#include "authSystem.h"

void AuthSystem::Register(ifstream& fin, ofstream& fout) {
    int type;
    fin >> type;

    Account newAccount;

    if (type == 1) {
        fin >> newAccount.companyName >> newAccount.businessNum >> newAccount.id >> newAccount.password;    
    } else if (type == 2) {
        fin >> newAccount.name >> newAccount.residentNumber >> newAccount.id >> newAccount.password;
    }

    accounts.push_back(newAccount);

}

void AuthSystem::Login(ifstream& fin, ofstream& fout) {

}

void AuthSystem::Logout(ifstream& fin, ofstream& fout) {


}

void AuthSystem::Withdraw(ifstream& fin, ofstream& fout) {


}


Account AuthSystem::getAccountInfo() {
    return accounts[accountNum];
}
