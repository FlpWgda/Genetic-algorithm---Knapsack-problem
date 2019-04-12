//
// Created by hp on 28.12.2018.
//
#include "iostream"
#include "CKnapsackProblem.h"
using namespace std;
template <class T>
vector<CKnapsackProblem<T>*> CKnapsackProblem<T>::KNAPSACKVEKTOR;
template <class T>
CKnapsackProblem<T>::CKnapsackProblem(vector<vector<int>> knapsack,int knapsackCapacity) {
    CKnapsackProblem::knapsackCapacity = knapsackCapacity;
    CKnapsackProblem::knapsack= knapsack;
    CKnapsackProblem::numberOfElements = knapsack.size();
}
template <class T>
int CKnapsackProblem<T>::countValue(vector<int> genotype) {
    return 0;
}
template <class T>
void CKnapsackProblem<T>::printKnapsack() {
    for(int i=0;i<knapsackCapacity;i++){
        cout << "[W: " << knapsack[i][0] << " R: "<< knapsack[i][1]<<"]";
    }

}
template class CKnapsackProblem<int>;
template class CKnapsackProblem<bool>;
template class CKnapsackProblem<double>;