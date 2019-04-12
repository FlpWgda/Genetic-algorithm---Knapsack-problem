//
// Created by hp on 14.11.2018.
//

#include "CMenuCommand.h"
#include "CCommand.h"
#include <iostream>
using namespace std;
CMenuCommand::CMenuCommand(string Nazwa, string Komenda, CCommand *ccommand,string helpText) {
    CMenuItem::nazwa = Nazwa;
    CMenuItem::komenda = Komenda;
    cCommand = ccommand;
    CMenuCommand::helpText = helpText;
}
void CMenuCommand::run(){
    cCommand->runCommand();
}
void CMenuCommand::help(){
    cout<< helpText<<endl;
}
string CMenuCommand::createNode() {
    string info= "{'" + nazwa + "'='"+ komenda + "'='" + helpText + "'}";
    return info;
}
void CMenuCommand::search2(CMenuItem *, string) {

}