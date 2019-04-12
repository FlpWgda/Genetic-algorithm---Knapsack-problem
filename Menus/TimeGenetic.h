//
// Created by hp on 21.01.2019.
//

#ifndef UNTITLED4_BOOLGENETIC_H
#define UNTITLED4_BOOLGENETIC_H

#include "CCommand.h"
#include "../CKnapsackProblem.h"
#include "../CGeneticAlgorithm.h"
#include "MutProb.h"
#include "CrossProb.h"
#include "PopSize.h"
#include "KnapsackList.h"

class TimeGenetic:public CCommand {
public:
    TimeGenetic(string parent,MutProb* mutProb,CrossProb* crossProb,PopSize* popSize,KnapsackList* knapsacks);
    virtual void runCommand();
private:
    string parent;
    MutProb* mutProb;
    CrossProb* crossProb;
    PopSize* popSize;
    KnapsackList* knapsacks;
};
#endif //UNTITLED4_BOOLGENETIC_H
