//
// Created by 김성민 on 2023/05/21.
//

#include "jobInformationSystem.h"




void JobInformationSystem::JobPostingRegistration(ifstream& fin, ofstream& fout, AuthSystem authSystem) {
    fout << "3.1. 채용 정보 등록" << endl;

    string work;
    int numOfPeople;
    string deadline;

    fin >> work >> numOfPeople >> deadline;
    fout << "> " << work << ' ' << numOfPeople << ' ' << deadline << endl;

    JobInformation newJobInformation(
        authSystem.getAccountInfo().id, 
        authSystem.getAccountInfo().companyName,
        authSystem.getAccountInfo().businessNum,
        work,
        numOfPeople,
        deadline
    );

    jobInformations.push_back(newJobInformation);
}

void JobInformationSystem::MyJobPosting(ifstream& fin, ofstream& fout, AuthSystem authSystem) {
    fout << "3.2. 등록된 채용 정보 조회" << endl;

    for (auto jobInfo : jobInformations) {
        if (jobInfo.getOwnerNum() == authSystem.getAccountInfo().id) {
            fout << "> " << jobInfo.getWork() << ' ' << jobInfo.getNumOfPeople() << ' ' << jobInfo.getDeadline() << endl;
        }
    }
}

JobInformation JobInformationSystem::Search(ifstream& fin, ofstream& fout, AuthSystem authSystem) {
    // fout << "4.1 로그인" << endl;

    // string id;
    // fin >> id;
    // authSystem.getAccountInfo();

}

void JobInformationSystem::Apply() {

}

void JobInformationSystem::ApplyInfo() {

}

void JobInformationSystem::WithdrawApply() {

}

