//
// Created by 김성민 on 2023/05/21.
//

#ifndef ASSIGNMENT3_AUTHSYSTEM_H
#define ASSIGNMENT3_AUTHSYSTEM_H


#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Account {
public:
    // 공통
    string id;
    string password;
    int accountType; // 회원 유형
    // 회사 회원
    string companyName;
    int businessNum;
    // 일반 회원
    string name;
    int residentNumber;
};

// TODO: 만들어놓고 클래스 나누기
class AuthSystem {
private:

    vector<Account> accounts;

    // 현재 로그인한 계정
    int accountNum = -1; // vector index

public:
    bool Login(ifstream& fin, ofstream& fout);
    bool Register(ifstream& fin, ofstream& fout);
    bool Logout(ifstream& fin, ofstream& fout);
    bool Withdraw(ifstream& fin, ofstream& fout);
    Account getAccountInfo();
};




#endif //ASSIGNMENT3_AUTHSYSTEM_H
