//
// Created by 김성민 on 2023/05/21.
//
#include <iostream>

#include "authSystem.h"

void AuthSystem::Register(ifstream& fin, ofstream& fout) {
    fout << "1.1 회원가입" << endl;

    int type;
    fin >> type;

    Account newAccount;

    if (type == 1) {
        fin >> newAccount.companyName >> newAccount.businessNum >> newAccount.id >> newAccount.password; 
        fout << "> " << type << ' ' << newAccount.companyName << ' ' << newAccount.businessNum << ' ' << newAccount.id << ' ' << newAccount.password << endl;   
    } else if (type == 2) {
        fin >> newAccount.name >> newAccount.residentNumber >> newAccount.id >> newAccount.password;
        fout << "> " << type << ' ' << newAccount.name << ' ' << newAccount.residentNumber << ' ' << newAccount.id << ' ' << newAccount.password << endl;
    }
    accounts.push_back(newAccount);
}

void AuthSystem::Login(ifstream& fin, ofstream& fout) {
    fout << "2.1 로그인" << endl;

    string id, pw;
    fin >> id >> pw;

    for (int i = 0; i < (int)accounts.size(); ++i) {
        if (accounts[i].id == id && accounts[i].password == pw) {
            accountNum = i;
            fout << "> " << accounts[i].id << ' ' << accounts[i].password << endl;
        }
    }
}

void AuthSystem::Logout(ifstream& fin, ofstream& fout) {
    fout << "2.2 로그아웃" << endl;

    string id;
    fin >> id;

    if (accounts[accountNum].id == id) {
        fout << "> " << accounts[accountNum].id << endl;
        accountNum = -1; // logout
    }
}

void AuthSystem::Withdraw(ifstream& fin, ofstream& fout) {
    fout << "1.2 회원탈퇴" << endl;

    string id;
    fin >> id;

    for (int i = 0; i < (int)accounts.size(); ++i) {
        if (accounts[i].id == id) {
            fout << "> " << accounts[i].id << endl;
            accounts.erase(accounts.begin() + i);
        }
    }
}


Account AuthSystem::getAccountInfo() {
    return accounts[accountNum];
}
