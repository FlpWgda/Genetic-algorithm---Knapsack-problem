//
// Created by hp on 28.12.2018.
//

#ifndef UNTITLED4_CINDIVIDUAL_H
#define UNTITLED4_CINDIVIDUAL_H

#include "CKnapsackProblem.h"
#include <vector>

using namespace std;
template <class T>
class CIndividual {
public:
    CIndividual(vector<T> genotype,CKnapsackProblem<int> *knapsack);
    CIndividual(CIndividual &copyC);
    vector<T> genotype;
    CKnapsackProblem<int>* knapsack;
    double countFitness();
    double fitness;
    CIndividual* cross(CIndividual* mate,int cuttingSpot);
    CIndividual<T>* operator+(CIndividual<T>* mate);
    void operator++(int input);
    void mutate(vector<int> mutations);
   /* CIndividual(int knapsackCapacity);
    int* mutate(int* array);
    int* fitness();
    int* cross(int* array);
    int* genotype[];*/

};


#endif //UNTITLED4_CINDIVIDUAL_H
