//
// Created by 김성민 on 2023/05/21.
//

#ifndef ASSIGNMENT3_JOBINFORMATIONSYSTEM_H
#define ASSIGNMENT3_JOBINFORMATIONSYSTEM_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>


#include "authSystem.h"

using namespace std;

class JobInformation {
private:
    string ownerNum; // 작성자 ID
    string companyName; // 회사 이름
    int businessNum; // 사업자 번호
    string work; // 업무
    int numOfPeople; // 인원 수
    string deadline; // 신청 마감일
public: 
    JobInformation(string ownerNum, string companyName, int businessNum, string work, int numOfPeople, string deadline) {
        this->ownerNum = ownerNum;
        this->companyName = companyName;
        this->businessNum = businessNum;
        this->work = work;
        this->numOfPeople = numOfPeople;
        this->deadline = deadline;
    };
    // ownerNum의 getter와 setter
    string getOwnerNum() const {
        return ownerNum;
    }

    void setOwnerNum(const string& owner) {
        ownerNum = owner;
    }

    // companyName의 getter와 setter
    string getCompanyName() const {
        return companyName;
    }

    void setCompanyName(const string& company) {
        companyName = company;
    }

    // businessNum의 getter와 setter
    int getBusinessNum() const {
        return businessNum;
    }

    void setBusinessNum(int business) {
        businessNum = business;
    }

    // work의 getter와 setter
    string getWork() const {
        return work;
    }

    void setWork(const string& job) {
        work = job;
    }

    // numOfPeople의 getter와 setter
    int getNumOfPeople() const {
        return numOfPeople;
    }

    void setNumOfPeople(int numPeople) {
        numOfPeople = numPeople;
    }

    // deadline의 getter와 setter
    string getDeadline() const {
        return deadline;
    }

    void setDeadline(const string& dueDate) {
        deadline = dueDate;
    }

};

class JobInformationSystem {
private:
    vector<JobInformation> jobInformations; // key
    vector<vector<JobInformation> > appliedJobInformations; // 지원한 채용 목록

public:
    void JobPostingRegistration(ifstream& fin, ofstream& fout, AuthSystem authSystem);
    void MyJobPosting(ifstream& fin, ofstream& fout, AuthSystem authSystem);
    void Search(ifstream& fin, ofstream& fout);
    void Apply(ifstream& fin, ofstream& fout, AuthSystem authSystem);
    void ApplyInfo(ifstream& fin, ofstream& fout, AuthSystem authSystem);
    void AddNewApplyment();
};



#endif //ASSIGNMENT3_JOBINFORMATIONSYSTEM_H
