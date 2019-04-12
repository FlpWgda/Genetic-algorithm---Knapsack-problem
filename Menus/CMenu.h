#ifndef UNTITLED_CMENU_H
#define UNTITLED_CMENU_H

#include <vector>
#include "CMenuItem.h"
#include "CMenuCommand.h"

class CMenu: public CMenuItem {
    public:
        CMenu();
        CMenu(string Nazwa, string Komenda);
        vector<CMenuItem*> tablicaC;
        CMenu* addMenu(string Nazwa,string Komenda);
        CMenu* addMenu2(CMenu* cMenu);
        CMenuCommand * addCommand(string Nazwa, string Komenda,CCommand *cCommand,string helpText);
        CMenuCommand * addCommand2(CMenuCommand* cMenuCommand);
        void run();
        void add(CMenuItem* item);
        virtual void search(CMenuItem*,string);
        void path(CMenuItem* root);
        virtual string createNode();
        virtual void search2(CMenuItem*,string);
};


#endif //UNTITLED_CMENU_H
