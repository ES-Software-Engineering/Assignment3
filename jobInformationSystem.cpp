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

bool compareByCompanyName(const JobInformation& job1, const JobInformation& job2) {
    return job1.getCompanyName() < job2.getCompanyName();
}

void JobInformationSystem::Search(ifstream& fin, ofstream& fout) {
    fout << "4.1 채용 정보 검색" << endl;

    string companyName;
    fin >> companyName;

    vector<JobInformation> matchingJobs;

    for (auto jobInfo : jobInformations) {
        if (jobInfo.getCompanyName() == companyName) {
            matchingJobs.push_back(jobInfo);
        }
    }

    sort(matchingJobs.begin(), matchingJobs.end(), compareByCompanyName);

    for (auto jobInfo : matchingJobs) {
        fout << "> " << companyName << ' ' << jobInfo.getBusinessNum() << ' ' << jobInfo.getWork() << ' ' << jobInfo.getNumOfPeople() << ' ' << jobInfo.getDeadline()<< endl;
    }

}

void JobInformationSystem::Apply(ifstream& fin, ofstream& fout, AuthSystem authSystem) {
    fout << "4.2 채용 지원" << endl;

    int businessNum;
    fin >> businessNum;

    for (auto jobInfo : jobInformations) {
        if(jobInfo.getBusinessNum() == businessNum) { 
            int curUserNum = authSystem.getAccountNum();
            appliedJobInformations[curUserNum].push_back(jobInfo);
            fout << "> " << jobInfo.getCompanyName() << ' ' << jobInfo.getBusinessNum() << ' ' << jobInfo.getWork() << endl;
        }
    }
}

void JobInformationSystem::ApplyInfo(ifstream& fin, ofstream& fout, AuthSystem authSystem) {
    fout << "4.3. 지원 정보 조회" << endl;
    int curUserNum = authSystem.getAccountNum();
    
    vector<JobInformation> matchingJobs;

    for (auto jobInfo : appliedJobInformations[curUserNum]) {
        matchingJobs.push_back(jobInfo);
    }

    sort(matchingJobs.begin(), matchingJobs.end(), compareByCompanyName);


    for (auto jobInfo : matchingJobs) {
        fout << "> " << jobInfo.getCompanyName() << ' ' << jobInfo.getBusinessNum() << ' ' << jobInfo.getWork() << ' ' << jobInfo.getNumOfPeople() << ' ' << jobInfo.getDeadline()<< endl;
    }

}

void JobInformationSystem::AddNewApplyment() { 
    appliedJobInformations.push_back(vector<JobInformation>());
}