//
// Created by hp on 23.01.2019.
//

#ifndef UNTITLED4_CROSSPROB_H
#define UNTITLED4_CROSSPROB_H

#include "CCommand.h"

class CrossProb :public CCommand {
public:
    CrossProb(double crossProb);
    virtual void runCommand();
    double crossProb;
};


#endif //UNTITLED4_CROSSPROB_H
