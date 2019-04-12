//
// Created by hp on 21.01.2019.
//

#ifndef UNTITLED4_KNAPSACKLIST_H
#define UNTITLED4_KNAPSACKLIST_H

#include "vector"
#include "CCommand.h"
#include "../CKnapsackProblem.h"
using namespace std;
class KnapsackList:public CCommand {
public:
    KnapsackList();
    void addKnapsack(vector<vector<int>> elem,int capacity);
    void deleteKnapsack(int pos);
    virtual void runCommand();
    void printKnapsack();
    vector<CKnapsackProblem<int>*> knapsacks;

};


#endif //UNTITLED4_KNAPSACKLIST_H
