//
// Created by 김성민 on 2023/05/21.
//
#include "mainSystem.h"

void MainSystem::run() {
    fin.open(inputFileName);
    fout.open(outputFileName);

    while (!fin.eof()) {
        int menuLv1, menuLv2;
        fin >> menuLv1 >> menuLv2;

        if (menuLv1 == 1 && menuLv2 == 1) { // 회원 가입
            authSystem.Register(fin, fout, &jobInformationSystem);
        } else if (menuLv1 == 1 && menuLv2 == 2) { // 회원 탈퇴
            authSystem.Withdraw(fin, fout);
        } else if (menuLv1 == 2 && menuLv2 == 1) { // 로그인
            authSystem.Login(fin, fout);
        } else if (menuLv1 == 2 && menuLv2 == 2) { // 로그아웃
            authSystem.Logout(fin, fout);
        } else if (menuLv1 == 3 && menuLv2 == 1) { // 채용 정보 등록
            jobInformationSystem.JobPostingRegistration(fin, fout, authSystem);
        } else if (menuLv1 == 3 && menuLv2 == 2) { // 등록된 채용 정보 조회
            jobInformationSystem.MyJobPosting(fin, fout, authSystem);
        } else if (menuLv1 == 4 && menuLv2 == 1) { // 채용 정보 검색
            jobInformationSystem.Search(fin, fout);
        } else if (menuLv1 == 4 && menuLv2 == 2) { // 채용 지원
            jobInformationSystem.Apply(fin, fout, authSystem);
        } else if (menuLv1 == 4 && menuLv2 == 3) { // 지원 정보 조회
            jobInformationSystem.ApplyInfo(fin, fout, authSystem);
        } 
        // else if (menuLv1 == 4 && menuLv2 == 4) { // 지원 취소
        //     jobInformationSystem.WithdrawApply();
        // } else if (menuLv1 == 5 && menuLv2 == 1) { // 지원 정보 통계
        //     // 함수 추가 정의 필요
        // } 
        else if (menuLv1 == 6 && menuLv2 == 1) { // 종료
            fout << "6.1. 종료" << endl;
            break;
        }
    }

    fin.close();
    fout.close();
}