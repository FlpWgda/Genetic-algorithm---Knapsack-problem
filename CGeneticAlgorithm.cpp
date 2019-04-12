//
// Created by hp on 28.12.2018.
//

#include "CGeneticAlgorithm.h"
#include "CKnapsackProblem.h"
#include "CIndividual.h"
#include <random>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>

template <class T>
CGeneticAlgorithm<T>::CGeneticAlgorithm(double mutProb, double crossProb, int popSize, CKnapsackProblem<int> *knapsack,int numberOfLoops) {

    CGeneticAlgorithm::knapsackCapacity = knapsack->knapsackCapacity;
    CGeneticAlgorithm::numberOfElements = knapsack->numberOfElements;
    CGeneticAlgorithm::knapsack = knapsack;
    CGeneticAlgorithm::mutProb = mutProb;
    CGeneticAlgorithm::crossProb = crossProb;
    CGeneticAlgorithm::popSize = popSize;
    CGeneticAlgorithm::pop = generatePop();
    knapsack->mutProb = CGeneticAlgorithm::mutProb;

    vector<T> emptyGenotype(numberOfElements,0);
    CGeneticAlgorithm::bestGenotype = new CIndividual<T>(emptyGenotype,knapsack);

    for(int i=0;i<numberOfLoops;i++) {
        for(int i=0;i<pop.size();i++){
            printOsobnik(pop[i]);
        }
        CGeneticAlgorithm::bestGenotype = findBestFit();
        cout<<"Best: "<<bestGenotype->fitness<<endl;

        CGeneticAlgorithm::pop = cross();
        cout<<"Po krzyzowaniu:"<<endl;
        for(int i=0;i<pop.size();i++) {
            printOsobnik(pop[i]);
        }
        cout<<"Po mutacji:"<<endl;
        mutate();
        for(int i=0;i<pop.size();i++) {
            printOsobnik(pop[i]);
        }

        CGeneticAlgorithm::bestGenotype = findBestFit();
        cout<<"Best2: "<<bestGenotype->fitness<<endl;

    }
    cout<<"Przystosowanie najlepszego osobnika(Fitness): "<<bestGenotype->fitness<<endl;
    cout<<"Genotyp najlepszego osobnika: ";
    for(int i=0;i<bestGenotype->genotype.size();i++){
        cout<<"["<<bestGenotype->genotype[i]<<"]";
    }
    cout<<"\n"<<endl;
}
template <class T>
CGeneticAlgorithm<T>::CGeneticAlgorithm(double mutProb, double crossProb, int popSize, CKnapsackProblem<int> *knapsack,double seconds) {

    CGeneticAlgorithm::knapsackCapacity = knapsack->knapsackCapacity;
    CGeneticAlgorithm::numberOfElements = knapsack->numberOfElements;
    CGeneticAlgorithm::knapsack = knapsack;
    CGeneticAlgorithm::mutProb = mutProb;
    CGeneticAlgorithm::crossProb = crossProb;
    CGeneticAlgorithm::popSize = popSize;
    CGeneticAlgorithm::pop = generatePop();
    knapsack->mutProb = CGeneticAlgorithm::mutProb;

    knapsack->mutProb = CGeneticAlgorithm::mutProb;

    vector<T> emptyGenotype(numberOfElements,0);
    CGeneticAlgorithm::bestGenotype = new CIndividual<T>(emptyGenotype,knapsack);

    clock_t start;
    double duration;
    start = clock();

    while(duration<seconds) {
        for(int i=0;i<pop.size();i++){
            printOsobnik(pop[i]);
        }
        CGeneticAlgorithm::bestGenotype = findBestFit();
        cout<<"Best: "<<bestGenotype->fitness<<endl;

        CGeneticAlgorithm::pop = cross();
        cout<<"Po krzyzowaniu:"<<endl;
        for(int i=0;i<pop.size();i++){
            printOsobnik(pop[i]);
        }
        cout<<"Po mutacji:"<<endl;
        mutate();
        for(int i=0;i<pop.size();i++){
            printOsobnik(pop[i]);
        }

        CGeneticAlgorithm::bestGenotype = findBestFit();
        cout<<"Best2: "<<bestGenotype->fitness<<endl;
        duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

    }
    cout<<"Przystosowanie najlepszego osobnika(Fitness): "<<bestGenotype->fitness<<endl;
    cout<<"Genotyp najlepszego osobnika: ";
    for(int i=0;i<bestGenotype->genotype.size();i++){
        cout<<"["<<bestGenotype->genotype[i]<<"]";
    }
    cout<<"\n"<<endl;
}
template <class T>
void CGeneticAlgorithm<T>::printOsobnik(CIndividual<T>* osobnik) {
    for(int i=0;i<numberOfElements;i++){
        cout<<"["<<osobnik->genotype[i]<<"]";
    }
    cout<<""<<endl;
}
template <>
vector<CIndividual<int>*> CGeneticAlgorithm<int>::generatePop() {
    vector<CIndividual<int>*> pom;
    for(int i=0;i<popSize;i++){
        vector<int> pom2;

        for (int n=0; n<numberOfElements; n++) {
            pom2.push_back(rand() % (knapsackCapacity+1));
        }
        pom.push_back(new CIndividual<int>(pom2,knapsack));
    }
    return pom;
}
template <>
vector<CIndividual<bool>*> CGeneticAlgorithm<bool>::generatePop() {
    vector<CIndividual<bool>*> pom;
    for(int i=0;i<popSize;i++){
        vector<bool> pom2;

        for (int n=0; n<numberOfElements; n++) {
            int boolValue = rand() % 2;
            if(boolValue == 0){
                pom2.push_back(false);
            }
            else{
                pom2.push_back(true);
            }
        }
        pom.push_back(new CIndividual<bool>(pom2,knapsack));
    }
    return pom;
}
template <>
vector<CIndividual<double>*> CGeneticAlgorithm<double>::generatePop() {
    vector<CIndividual<double>*> pom;
    for(int i=0;i<popSize;i++){
        vector<double> pom2;

        for (int n=0; n<numberOfElements; n++) {
            int integerPart = rand() % (knapsack->knapsackCapacity);
            double fractionPart = (rand() % 101)*0.01;
            pom2.push_back(integerPart+fractionPart);
        }
        pom.push_back(new CIndividual<double>(pom2,knapsack));
    }
    return pom;
}
template <class T>
CIndividual<T>* CGeneticAlgorithm<T>::findBestFit() {
    for(int i=0;i<pop.size();i++){
        if(pop[i]->fitness>bestGenotype->fitness){
            delete bestGenotype;
            bestGenotype=new CIndividual<T>(*(pop[i]));
        }
    }
    return bestGenotype;
}

/*template <class T>
vector<CIndividual<T>*> CGeneticAlgorithm<T>::cross() {
    vector<CIndividual<T>*> newPop;

    while(newPop.size()<popSize) {
        CIndividual<T> *pom1, *pom2, *parent1, *parent2;
        pom1 = pop[rand() % pop.size()];
        pom2 = pop[rand() % pop.size()];
        if (pom1->fitness >= pom2->fitness) {
            parent1 = pom1;
        } else {
            parent1 = pom2;
        }
        pom1 = pop[rand() % pop.size()];
        pom2 = pop[rand() % pop.size()];
        if (pom1->fitness >= pom2->fitness) {
            parent2 = pom1;
        } else {
            parent2 = pom2;
        }
        double crossRandom = (rand() % 1001) * 0.001;
        if(crossRandom < crossProb){
            int cuttingSpot = rand() % (pop[0]->genotype.size()-1)+1;
                newPop.push_back((*parent1+parent2));
            if(popSize-newPop.size()>0){
                newPop.push_back((*parent2+parent1));
            }
        }
        else{
            newPop.push_back(new CIndividual<T>(*parent1));
            if(popSize-newPop.size()>0){
                newPop.push_back(new CIndividual<T>(*parent2));
            }
        }
    }
    for(int i=0;i<popSize;i++){
        delete pop[i];
    }
    return newPop;
}
template <class T>
void CGeneticAlgorithm<T>::mutate(){

    for(int i=0;i<pop.size();i++){
        (*pop[i])++;
    }
}*/
template <class T>
vector<CIndividual<T>*> CGeneticAlgorithm<T>::cross() {
    vector<CIndividual<T>*> newPop;

    while(newPop.size()<popSize) {
        CIndividual<T> *pom1, *pom2, *parent1, *parent2;
        pom1 = pop[rand() % pop.size()];
        pom2 = pop[rand() % pop.size()];
        if (pom1->fitness >= pom2->fitness) {
            parent1 = pom1;
        } else {
            parent1 = pom2;
        }
        pom1 = pop[rand() % pop.size()];
        pom2 = pop[rand() % pop.size()];
        if (pom1->fitness >= pom2->fitness) {
            parent2 = pom1;
        } else {
            parent2 = pom2;
        }
        double crossRandom = (rand() % 1001) * 0.001;
        if(crossRandom < crossProb){
            int cuttingSpot = rand() % (pop[0]->genotype.size()-1)+1;
            newPop.push_back(*parent1+parent2);
            if(popSize-newPop.size()>0){
                newPop.push_back(*parent2+parent1);
            }
        }
        else{
            newPop.push_back(new CIndividual<T>(*parent1));
            if(popSize-newPop.size()>0){
                newPop.push_back(new CIndividual<T>(*parent2));
            }
        }
    }
    for(int i=0;i<popSize;i++){
        delete pop[i];
    }
    return newPop;
}
template <class T>
void CGeneticAlgorithm<T>::mutate(){


    for(int i=0;i<pop.size();i++){
        (*pop[i])++;
    }
}
template class CGeneticAlgorithm<int>;
template class CGeneticAlgorithm<bool>;
template class CGeneticAlgorithm<double>;