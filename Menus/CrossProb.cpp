//
// Created by hp on 23.01.2019.
//

#include "CrossProb.h"
#include "iostream"
#include <limits>
using namespace std;
CrossProb::CrossProb(double crossProb) {
    CrossProb::crossProb = crossProb;
}
void CrossProb::runCommand() {
    cout << "Podaj prawdopodob. krzyzowania w %(obecnie:" << crossProb<< "): ";
    while(!(cin >> crossProb)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nieprawidlowa liczba. Sprobuj ponownie: ";
    }
    crossProb = crossProb*0.01;
}