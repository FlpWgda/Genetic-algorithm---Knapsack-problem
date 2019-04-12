#include "CMenu.h"
#include "iostream"
#include "string"
#include "vector"
using namespace std;
CMenu::CMenu(string Nazwa, string Komenda) {
    CMenuItem::nazwa= Nazwa;
    CMenuItem::komenda= Komenda;
}
CMenu::CMenu(){

}
void CMenu::run() {
    string komenda;
    cout << CMenu::nazwa << " (" << CMenu::komenda << ")" <<endl;
    cout << "" << endl;
    for(int i;i<tablicaC.size();i++){
        cout << tablicaC[i]->nazwa << " (" <<  tablicaC[i]->komenda<< ")" <<endl;
    }

    cout << "Podaj komende: " ;
    cin.clear();
    getline(cin,komenda);
    cin.clear();

        bool czyJest = false;

        for(int i=0;i<tablicaC.size();i++){
            if(tablicaC[i]->komenda==komenda){

                czyJest = true;
                tablicaC[i]->run();
                break;
            }
        }
        if (komenda=="back"){
            string a=" ";

            cout<<""<<endl;

        }
        else if (komenda.substr(0,4)=="help"){
            for(int i=0;i<tablicaC.size();i++){
                if(komenda.substr(5) == tablicaC[i]->komenda){
                    tablicaC[i]->help();
                    break;
                }
            }
            cout << "brak komendy" << endl << endl;
            run();
        }
        else if (komenda.substr(0,6)=="search"){

                CMenuItem* lastItem= this;
                while(lastItem->parent != NULL){
                    lastItem= lastItem->parent;
                }
                search(lastItem,komenda.substr(7));
                /*if(komenda.substr(7) == tablicaC[i]->komenda){
                    tablicaC[i]->search();
                }*/
            cout<<" "<<endl;
            run();
        }
        else if(!czyJest){
            cout << "Nie ma takiej pozycji" << endl << endl;
            run();
        }
        else run();



}
CMenu * CMenu::addMenu(string Nazwa, string Komenda){
    CMenuItem* item = new CMenu(Nazwa,Komenda);
    CMenu::tablicaC.push_back(item);
    item->parent=this;
    return dynamic_cast<CMenu *>(item);

}
CMenuCommand * CMenu::addCommand(string Nazwa, string Komenda, CCommand *cCommand,string helpText){
    CMenuItem* item = new CMenuCommand(Nazwa,Komenda,cCommand,helpText);
    CMenu::tablicaC.push_back(item);
    item->parent=this;
    return dynamic_cast<CMenuCommand *>(item);
}
CMenu * CMenu::addMenu2(CMenu *cMenu){
    CMenu::tablicaC.push_back(cMenu);
    cMenu->parent=this;
    return cMenu;
}
CMenuCommand * CMenu::addCommand2(CMenuCommand *cMenuCommand){
    CMenu::tablicaC.push_back(cMenuCommand);
    cMenuCommand->parent=this;
    return cMenuCommand;
}


void CMenu::search(CMenuItem* rootMenu,string komendaSub) {
    if(dynamic_cast<CMenuCommand*>(rootMenu) != nullptr){
        if(rootMenu->komenda==komendaSub){
            /*path(rootMenu);*/
        };
    }
    else{
        CMenu* root = dynamic_cast<CMenu *>(rootMenu);
        for(int i=0;i<(root->tablicaC.size());i++) {
            if(root->tablicaC[i]->komenda==komendaSub){
                path(root->tablicaC[i]);
            };
            search(root->tablicaC[i],komendaSub);
        }
    }
}
void CMenu::path(CMenuItem* root){
    CMenuItem* lastItem= root;
    string path=" ";
    while(lastItem->parent != NULL){
        path= " -> " + lastItem->komenda + path;
        lastItem= lastItem->parent;
    }
    path= lastItem->komenda + path;
    cout<<path<<endl;
}

string CMenu::createNode() {
    string info= "{'" + nazwa + "'='"+ komenda +"'";
    for(int i=0;i<tablicaC.size();i++){
        info=info + "=" + tablicaC[i]->createNode() ;
    }
    info= info + "}";
    return info;
}

void CMenu::search2(CMenuItem* rootMenu,string komendaSub) {
    CMenu* root = dynamic_cast<CMenu *>(rootMenu);
    for(int i=0;i<(root->tablicaC.size());i++) {
        if(root->tablicaC[i]->komenda==komendaSub){
            path(root->tablicaC[i]);
        };
        search2(root->tablicaC[i],komendaSub);
    /*if(dynamic_cast<CMenuCommand*>(rootMenu) != nullptr){
        if(rootMenu->komenda==komendaSub){
            /*path(rootMenu);*/
    /*    };
    }
    else{
        CMenu* root = dynamic_cast<CMenu *>(rootMenu);
        for(int i=0;i<(root->tablicaC.size());i++) {
            if(root->tablicaC[i]->komenda==komendaSub){
                path(root->tablicaC[i]);
            };
            search2(root->tablicaC[i],komendaSub);
        }*/
    }
}