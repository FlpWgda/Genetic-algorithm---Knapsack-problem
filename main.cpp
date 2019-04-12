#include <iostream>
#include "CKnapsackProblem.h"
#include "CGeneticAlgorithm.h"
#include "Menus/CMenu.h"
#include "Menus/CMenuCommand.h"
#include "Menus/TimeGenetic.h"
#include "Menus/LoopGenetic.h"
#include "Menus/KnapsackList.h"
#include <random>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;
int main() {
    srand (time(NULL));

    /*clock_t start;
    double duration;
    start = clock();

    vector<vector<int>> knapsack1{{6,4},{1,1},{4,3},{3,2},{7,3}};
    int knapsackCapacity1 = 10;*/

    MutProb *mp = new MutProb(0.2);
    CrossProb *cp = new CrossProb(0.6);
    PopSize *ps = new PopSize(7);
    KnapsackList *kl = new KnapsackList();
    CMenu *cmenu1 = new CMenu("Menu glowne","menu");
        CMenu *menu1 = cmenu1->addMenu("Algorytm genetyczny","genetic");
            CMenu *podmenu1 = menu1->addMenu("Bool genetic algorithm","bool");
                CMenuCommand *podmenu1_1 = podmenu1->addCommand("Czasowy", "time", (new TimeGenetic("bool",mp,cp,ps,kl)), "helpText");
                CMenuCommand *podmenu1_2 = podmenu1->addCommand("Petlowy", "loop", (new LoopGenetic("bool",mp,cp,ps,kl)), "helpText");
            CMenu *podmenu2 = menu1->addMenu("Int genetic algorithm","int");
                CMenuCommand *podmenu2_1 = podmenu2->addCommand("Czasowy", "time", (new TimeGenetic("int",mp,cp,ps,kl)), "helpText");
                CMenuCommand *podmenu2_2 = podmenu2->addCommand("Petlowy", "loop", (new LoopGenetic("int",mp,cp,ps,kl)), "helpText");
            CMenu *podmenu3 = menu1->addMenu("Double genetic algorithm","double");
                CMenuCommand *podmenu3_1 = podmenu3->addCommand("Czasowy", "time", (new TimeGenetic("double",mp,cp,ps,kl)), "helpText");
                CMenuCommand *podmenu3_2 = podmenu3->addCommand("Petlowy", "loop", (new LoopGenetic("double",mp,cp,ps,kl)), "helpText");
        CMenuCommand *c1 = cmenu1->addCommand("Dodaj knapsack", "knapsack", kl, "helpText");
        CMenuCommand *c2 = cmenu1->addCommand("Zmien prawdopod. mutacji","mutProb", mp,"helpText");
        CMenuCommand *c3 = cmenu1->addCommand("Zmien prawdopod. krzyzowania","crossProb", cp,"helpText");
        CMenuCommand *c4 = cmenu1->addCommand("Zmien rozmiar popoulacji","popSize", ps,"helpText");

    cmenu1->run();

    /*CKnapsackProblem<int>* ckp1 = new CKnapsackProblem<int>(knapsack1,knapsackCapacity1);
    CGeneticAlgorithm<bool>* cga1 = new CGeneticAlgorithm<bool>(0.4,0.6,6,ckp1,20);
    CIndividual<bool>* ci1 = cga1->bestGenotype;
    cout<<"Fitness: "<<ci1->fitness<<endl;;
    cout<<"Genotype: ";;
    for(int i=0;i<ci1->genotype.size();i++){
        cout<<ci1->genotype[i];
    }
    delete ckp1,cga1,ci1;*/

    return 0;
}