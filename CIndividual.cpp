//
// Created by hp on 28.12.2018.
//
#include <random>
#include <ctime>
#include "iostream"
#include "CIndividual.h"


template <class T>
CIndividual<T>::CIndividual(vector<T> genotype,CKnapsackProblem<int> *knapsack) {
    CIndividual::genotype = genotype;
    CIndividual::knapsack = knapsack;
    fitness = countFitness();
}
template <class T>
CIndividual<T>::CIndividual(CIndividual<T> &copyC) {
    CIndividual::fitness = copyC.fitness;
    CIndividual::knapsack = copyC.knapsack;
    CIndividual::genotype = copyC.genotype;
}
template <class T>
double CIndividual<T>::countFitness() {
    double fitness = 0;
    double capacity = 0;
    for(int i=0;i<genotype.size();i++){
            fitness += genotype[i]*knapsack->knapsack[i][0];
            capacity += genotype[i]*knapsack->knapsack[i][1];
    }
    if(capacity<=knapsack->knapsackCapacity){
        //*cout<<"Fitness: "<<fitness<<endl;
        return fitness;
    }
    else{
        //*cout<<"Fitness: "<<0<<endl;
        return 0;
    }
}


template <class T>
CIndividual<T>* CIndividual<T>::operator+(CIndividual<T>* mate) {
    int cuttingSpot = (rand() % (genotype.size()-1))+1;
    vector<T> newGenotype;
    CIndividual* pom;
    for(int i=0;i<cuttingSpot;i++){
        newGenotype.push_back(genotype[i]);
    }
    for(int i=cuttingSpot;i<genotype.size();i++){
        newGenotype.push_back(mate->genotype[i]);
    }
    pom = new CIndividual<T>(newGenotype,knapsack);
    return pom;
}
template <>
void CIndividual<bool>::operator++(int){
    for(int j=0;j<genotype.size();j++){
        double random = (rand() % 1001)*0.001;
        if(random<knapsack->mutProb){
            if(genotype[j]== true){
                genotype[j]=0;
                //*cout<<"gen: " <<genotype[j];
            }
            else{
                genotype[j]=1;
                //*cout<<"gen: " <<genotype[j];
            }
        }
    }
    fitness = countFitness();
}
template <>
void CIndividual<int>::operator++(int){                 //++ int

    for(int j=0;j<genotype.size();j++){
        double random = (rand() % 1001)*0.001;
        if(random<knapsack->mutProb){
            int operation = rand() % 2;
            if(operation==0){
                if(genotype[j]>0){
                    genotype[j]--;
                }
            }
            else{
                if(genotype[j]<knapsack->knapsackCapacity){
                    genotype[j]++;
                }
            }
        }
    }
    fitness = countFitness();
}
template <>
void CIndividual<double>::operator++(int){               //++ double

    for(int j=0;j<genotype.size();j++){
        double random = (rand() % 1001)*0.001;
        if(random<knapsack->mutProb){
            int integerPart = rand() % (knapsack->knapsackCapacity);
            double fractionPart = (rand() % 101)*0.01;
            int operation = rand() % 2;
            if(operation==0){
                genotype[j] -= fractionPart;
                if(genotype[j]<0){
                    genotype[j]++;
                }
            }
            else{
                genotype[j] += fractionPart;
                if(genotype[j]>knapsack->knapsackCapacity){
                    genotype[j]--;
                }
            }
        }
    }
    //*cout<<"\n"<<endl;
    fitness = countFitness();
}

/* <class T>
CIndividual<T>* CIndividual<T>::cross(CIndividual<T> *mate,int cuttingSpot) {
    vector<T> newGenotype;
    CIndividual* pom;
    for(int i=0;i<cuttingSpot;i++){
        newGenotype.push_back(genotype[i]);
    }
    for(int i=cuttingSpot;i<genotype.size();i++){
        newGenotype.push_back(mate->genotype[i]);
    }
    pom = new CIndividual(newGenotype,knapsack);
    return pom;
}
template <class T>
void CIndividual<T>::mutate(vector<int> mutations) {
    for(int i=0;i<mutations.size();i++){
        if(genotype[mutations[i]]==0){
            genotype[mutations[i]]=1;
        }
        else{
            genotype[mutations[i]]=0;
        }
    }
    fitness = countFitness();
}*/
template <class T>
CIndividual<T>* CIndividual<T>::cross(CIndividual<T> *mate,int cuttingSpot) {
    vector<T> newGenotype;
    CIndividual* pom;
    for(int i=0;i<cuttingSpot;i++){
        newGenotype.push_back(genotype[i]);
    }
    for(int i=cuttingSpot;i<genotype.size();i++){
        newGenotype.push_back(mate->genotype[i]);
    }
    pom = new CIndividual<T>(newGenotype,knapsack);
    return pom;
}
template <class T>
void CIndividual<T>::mutate(vector<int> mutations) {
    for(int i=0;i<mutations.size();i++){
        if(genotype[mutations[i]]==0){
            genotype[mutations[i]]=1;
        }
        else{
            genotype[mutations[i]]=0;
        }
    }
    fitness = countFitness();
}
template class CIndividual<int>;
template class CIndividual<bool>;
template class CIndividual<double>;
