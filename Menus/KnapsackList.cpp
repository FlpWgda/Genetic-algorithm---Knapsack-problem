//
// Created by hp on 21.01.2019.
//

#include <iostream>
#include "KnapsackList.h"
using namespace std;
KnapsackList::KnapsackList(){
    vector<vector<int>> knapsack1{{6,4},{1,1},{4,3},{3,2},{7,3}};
    vector<vector<int>> knapsack2{{6,4},{1,1},{4,3},{3,2},{8,2},{3,5}};
    knapsacks.push_back(new CKnapsackProblem<int>(knapsack1,5));
    knapsacks.push_back(new CKnapsackProblem<int>(knapsack2,6));

}

void KnapsackList::runCommand(){
    int capacity;
    vector<vector<int>> knapsack1;
    cout<<"Podaj wilekosc plecaka"<<endl;
    cin >> capacity;
    for(int i=0;i<capacity;i++){
        int fitness;
        int capacity;
        cout<<"Podaj wartosc elementu"<<endl;
        cin>>fitness;
        cout<<"Podaj rozmiar elementu"<<endl;
        cin>>capacity;
        knapsack1.push_back(vector<int>{fitness,capacity});
    }
    knapsacks.push_back(new CKnapsackProblem<int>(knapsack1,capacity));
    cout<<"Dodano plecak do listy"<<endl;
}
void KnapsackList::printKnapsack() {
    for(int i=0;i<knapsacks.size();i++){
        for(int j=0;j<knapsacks[i]->knapsackCapacity;j++){
            cout << "[W: " << knapsacks[i]->knapsack[j][0] << " R: "<< knapsacks[i]->knapsack[j][1]<<"]";
        }
        cout<< ""<<endl;
    }

}
/*void KnapsackList::addKnapsack(vector<vector<int>> elem,int capacity) {
    knapsacks.push_back(new CKnapsackProblem<int>(elem,capacity));
}
void KnapsackList::deleteKnapsack(int pos){
    knapsacks.erase(knapsacks.begin()+(pos-1));
}
*/