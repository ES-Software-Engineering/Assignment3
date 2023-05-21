//
// Created by 김성민 on 2023/05/21.
//
#include <iostream>

#include "jobInformationSystem.h"


void JobInformationSystem::JobPostingRegistration(ifstream& fin, ofstream& fout) {
    fout << "3.1. 채용 정보 등록" << endl;

    string work;
    int numOfPeople;
    string deadline;

    fin >> work >> numOfPeople >> deadline;
    fout << "> " << work << ' ' << numOfPeople << ' ' << deadline << endl;

    JobInformation newJobInformation;
    newJobInformation.ownerNum = authSystem.getAccountInfo().id;
    newJobInformation.companyName = authSystem.getAccountInfo().companyName;
    newJobInformation.businessNum = authSystem.getAccountInfo().businessNum;
    newJobInformation.work = work;
    newJobInformation.numOfPeople = numOfPeople;
    newJobInformation.deadline = deadline;

    jobInformations.push_back(newJobInformation);
}


void JobInformationSystem::MyJobPosting(ifstream& fin, ofstream& fout) {
    fout << "3.2. 등록된 채용 정보 조회" << endl;

    for (const JobInformation& jobInfo : jobInformations) {
        if (jobInfo.ownerNum == authSystem.getAccountInfo().id) {
            fout << "> " << jobInfo.work << ' ' << jobInfo.numOfPeople << ' ' << jobInfo.deadline << endl;
        }
    }
}





JobInformation JobInformationSystem::Search() {

}

void JobInformationSystem::Apply() {

}

void JobInformationSystem::ApplyInfo() {

}

void JobInformationSystem::WithdrawApply() {

}

