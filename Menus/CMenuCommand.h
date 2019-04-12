//
// Created by hp on 14.11.2018.
//

#ifndef UNTITLED_CMENUCOMMAND_H
#define UNTITLED_CMENUCOMMAND_H

#include "CMenuItem.h"
#include "CCommand.h"

class CMenuCommand: public CMenuItem{
public:
    CMenuCommand(string Nazwa,string Komenda, CCommand *ccommand,string helpText);
    void run();
    virtual void help();
    string helpText;
    virtual string createNode();
    virtual void search2(CMenuItem*,string);

private:
    CCommand* cCommand;
};


#endif //UNTITLED4_CMENUCOMMAND_H
