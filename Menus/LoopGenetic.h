//
// Created by hp on 21.01.2019.
//

#ifndef UNTITLED4_INTGENETIC_H
#define UNTITLED4_INTGENETIC_H

#include "CCommand.h"
#include "../CKnapsackProblem.h"
#include "../CGeneticAlgorithm.h"
#include "PopSize.h"
#include "CrossProb.h"
#include "MutProb.h"
#include "KnapsackList.h"

using namespace std;

class LoopGenetic:public CCommand {
public:
    LoopGenetic(string parent,MutProb* mutProb,CrossProb* crossProb,PopSize* popSize,KnapsackList* knapsacks);
    virtual void runCommand();
private:
    string parent;
    MutProb* mutProb;
    CrossProb* crossProb;
    PopSize* popSize;
    KnapsackList* knapsacks;
};


#endif //UNTITLED4_INTGENETIC_H
