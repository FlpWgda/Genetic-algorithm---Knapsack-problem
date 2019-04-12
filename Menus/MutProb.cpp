//
// Created by hp on 23.01.2019.
//

#include "MutProb.h"
#include "iostream"
#include <limits>
using namespace std;
MutProb::MutProb(double mutProb) {
    MutProb::mutProb = mutProb;
}
void MutProb::runCommand() {
    cout << "Podaj prawdopodob. mutacji w %(obecnie:" << mutProb<< "): ";
    while(!(cin >> mutProb)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nieprawidlowa liczba. Sprobuj ponownie: ";
    }
    mutProb = mutProb*0.01;
}