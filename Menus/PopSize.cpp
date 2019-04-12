//
// Created by hp on 23.01.2019.
//

#include "PopSize.h"
#include "iostream"
#include <limits>
using namespace std;
PopSize::PopSize(int popSize) {
    PopSize::popSize = popSize;
}
void PopSize::runCommand() {
    cout << "Podaj licznosc populacji(obecnie:" << popSize<< "): ";
    while(!(cin >> popSize)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nieprawidlowa liczba. Sprobuj ponownie: ";
    }
}