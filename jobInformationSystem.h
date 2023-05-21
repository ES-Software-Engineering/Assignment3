//
// Created by 김성민 on 2023/05/21.
//

#ifndef ASSIGNMENT3_JOBINFORMATIONSYSTEM_H
#define ASSIGNMENT3_JOBINFORMATIONSYSTEM_H

#include <vector>
#include <string>
#include <fstream>

#include "authSystem.h"

using namespace std;

class JobInformation {
public:
    string ownerNum; // 작성자 ID
    string companyName; // 회사 이름
    int businessNum; // 사업자 번호
    string work; // 업무
    int numOfPeople; // 인원 수
    string deadline; // 신청 마감일
};


class JobInformationSystem {
private:
    vector<JobInformation> jobInformations; // key
    AuthSystem authSystem;

public:
    void JobPostingRegistration(ifstream& fin, ofstream& fout);
    void MyJobPosting(ifstream& fin, ofstream& fout);
    JobInformation Search();
    void Apply();
    void ApplyInfo();
    void WithdrawApply();
};



#endif //ASSIGNMENT3_JOBINFORMATIONSYSTEM_H
