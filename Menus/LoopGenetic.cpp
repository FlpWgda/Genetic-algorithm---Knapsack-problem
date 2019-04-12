//
// Created by hp on 21.01.2019.
//

#include <limits>
#include "LoopGenetic.h"
#include "CMenuCommand.h"
#include "iostream"
#include "vector"

using namespace std;
LoopGenetic::LoopGenetic(string parent,MutProb* mutProb,CrossProb* crossProb,PopSize* popSize,KnapsackList* knapsacks) {
    LoopGenetic::parent=parent;
    LoopGenetic::mutProb=mutProb;
    LoopGenetic::crossProb=crossProb;
    LoopGenetic::popSize=popSize;
    LoopGenetic::knapsacks=knapsacks;
}
void LoopGenetic::runCommand() {
    cout << "Podaj liczbe petli: ";
    int numOfLoops;
    while(!(cin >> numOfLoops)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nieprawidlowa liczba. Sprobuj ponownie: ";
    }
    cout<<"Wybierz knapsack"<<endl;
    knapsacks->printKnapsack();
    int whichKnapsack;
    do{
        cin >> whichKnapsack;
    }while(whichKnapsack<0||whichKnapsack>(knapsacks->knapsacks.size()-1));

    if(parent=="bool"){
        new CGeneticAlgorithm<bool>(mutProb->mutProb,crossProb->crossProb,popSize->popSize,knapsacks->knapsacks[whichKnapsack],numOfLoops);
    }
    else if(parent=="int"){
        new CGeneticAlgorithm<int>(mutProb->mutProb,crossProb->crossProb,popSize->popSize,knapsacks->knapsacks[whichKnapsack],numOfLoops);
    }
    else{
        new CGeneticAlgorithm<double>(mutProb->mutProb,crossProb->crossProb,popSize->popSize,knapsacks->knapsacks[whichKnapsack],numOfLoops);
    }

}