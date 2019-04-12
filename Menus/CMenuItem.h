//
// Created by hp on 14.11.2018.
//

#ifndef UNTITLED_CMENUITEM_H
#define UNTITLED_CMENUITEM_H

#include <string>
using namespace std;

class CMenuItem {
public:
    string komenda;
    string nazwa;
    CMenuItem* parent= NULL;
    virtual void run() = 0;
    virtual void help();
    virtual void search(CMenuItem*,string);
    virtual string createNode();
    virtual void search2(CMenuItem*,string);
private:

};


#endif //UNTITLED_CMENUITEM_H
