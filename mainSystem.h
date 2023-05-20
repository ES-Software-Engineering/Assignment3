//
// Created by 김성민 on 2023/05/21.
//

#ifndef ASSIGNMENT3_MAINSYSTEM_H
#define ASSIGNMENT3_MAINSYSTEM_H

#include <string>
#include <fstream>

#include "authSystem.h"
#include "jobInformationSystem.h"

using namespace std;

class MainSystem {
private:
    const string inputFileName = "input.txt";
    const string outputFileName = "output.txt";

    ifstream fin;
    ofstream fout;
    AuthSystem authSystem;
    JobInformationSystem jobInformationSystem;

public:
    void run();
};


#endif //ASSIGNMENT3_MAINSYSTEM_H
