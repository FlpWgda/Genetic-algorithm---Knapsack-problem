#ifndef UNTITLED4_CGENETICALGORITHM_H
#define UNTITLED4_CGENETICALGORITHM_H

#include "CKnapsackProblem.h"
#include "CIndividual.h"
#include <vector>
#include <array>

using namespace std;
template <class T>
class CGeneticAlgorithm {
public:
    CGeneticAlgorithm(double mutProb,double crossProb,int popSize,CKnapsackProblem<int>* knapsack,int numberOfLoops);
    CGeneticAlgorithm(double mutProb,double crossProb,int popSize,CKnapsackProblem<int>* knapsack,double seconds);
    CKnapsackProblem<int> *knapsack;
    double crossProb;
    double mutProb;
    int popSize;
    int knapsackCapacity;
    int numberOfElements;
    vector<CIndividual<T>*> generatePop();
    vector<CIndividual<T>*> pop;
    CIndividual<T>* bestGenotype;
    CIndividual<T>* findBestFit();
    vector<CIndividual<T>*> cross();
    void mutate();
    void printOsobnik(CIndividual<T>* osobnik);

};


#endif //UNTITLED4_CGENETICALGORITHM_H
