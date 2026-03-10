#include <iostream>
#include <fstream>
#include "money.h"
using namespace std;

void normalize(Money* a){
    a->grn = a->grn + a->kop / 100;
    a->kop = a->kop % 100;
}

void add(Money* a, Money other){
    a->grn = a->grn + other.grn;
    a->kop = a->kop + other.kop;

    normalize(a);
}

void multiply(Money* a, int number){
    a->grn = a->grn * number;
    a->kop = a->kop * number;

    normalize(a);
}

void round(Money* a){
    int specified_rounding = a->kop % 10;

    if(specified_rounding < 5){
        a->kop = a->kop - specified_rounding;
    } 
    else {
        a->kop = a->kop + (10 - specified_rounding);
    }

    normalize(a);
}

void print(Money a){
    cout << a.grn << " grn " << a.kop << " kop" << endl;
}


void lab() {
   
    ifstream file("input.txt"); 
    
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    Money total = {0, 0}; 
    Money item;
    int g, q;
    short k;

    while (file >> g >> k >> q) {
        item.grn = g;
        item.kop = k;

        multiply(&item, q);
        add(&total, item);
    }

    cout << "Total amount: ";
    print(total);

    round(&total);
    cout << "Amount to be paid: ";
    print(total);

    file.close();
}
