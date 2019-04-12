//
// Created by hp on 28.12.2018.
//

#ifndef UNTITLED4_CKNAPSACKPROBLEM_H
#define UNTITLED4_CKNAPSACKPROBLEM_H
#include <vector>
#include "string"
using namespace std;
template <class T>
class CKnapsackProblem {
public:
    CKnapsackProblem(vector<vector<int>> knapsack, int knapsackCapacity);
    int countValue(vector<int> genotype);
    vector<vector<int>> knapsack;
    int knapsackCapacity;
    int numberOfElements;
    double mutProb;
    static vector<CKnapsackProblem<T>*> KNAPSACKVEKTOR;
    void printKnapsack();



};


#endif //UNTITLED4_CKNAPSACKPROBLEM_H
