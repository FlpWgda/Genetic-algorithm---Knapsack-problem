//
// Created by hp on 23.01.2019.
//

#ifndef UNTITLED4_MUTPROB_H
#define UNTITLED4_MUTPROB_H

#include "CCommand.h"

class MutProb :public CCommand {
public:
    MutProb(double mutProb);
    virtual void runCommand();
    double mutProb;
};


#endif //UNTITLED4_MUTPROB_H
