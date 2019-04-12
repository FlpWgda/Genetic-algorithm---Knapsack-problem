//
// Created by hp on 23.01.2019.
//

#ifndef UNTITLED4_POPSIZE_H
#define UNTITLED4_POPSIZE_H

#include "CCommand.h"

class PopSize :public CCommand {
public:
    PopSize(int popSize);
    virtual void runCommand();
    int popSize;
};


#endif //UNTITLED4_POPSIZE_H
