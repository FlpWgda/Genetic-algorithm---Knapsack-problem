//
// Created by hp on 21.01.2019.
//

#include "TimeGenetic.h"
#include <limits>
#include "iostream"
using namespace std;
TimeGenetic::TimeGenetic(string parent,MutProb* mutProb,CrossProb* crossProb,PopSize* popSize,KnapsackList* knapsacks) {
    TimeGenetic::parent = parent;
    TimeGenetic::mutProb=mutProb;
    TimeGenetic::crossProb=crossProb;
    TimeGenetic::popSize=popSize;
    TimeGenetic::knapsacks=knapsacks;
}
void TimeGenetic::runCommand() {
    cout << "Podaj liczbe sekund: ";
    int numOfLoops2;
    while(!(cin >> numOfLoops2)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nieprawidlowa liczba. Sprobuj ponownie: ";
    }
    double numOfLoops = numOfLoops2;
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