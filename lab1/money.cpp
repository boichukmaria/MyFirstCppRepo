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
}

void multiply(Money* a, int number){
    a->grn = a->grn * number;
    a->kop = a->kop * number;
}

void round(Money* a){
    int specified_rounding = a->kop % 10;

    if(specified_rounding < 5){
        a->kop = a->kop - specified_rounding;
    } 
    else {
        a->kop = a->kop + (10 - specified_rounding);
    }
}

void Print(Money* a){
    normalize(a);
    cout << a->grn << " grn " << a->kop << " kop" << endl;
}


void lab() {
   
   FILE *file;
int err = fopen_s(&file, "input.txt", "r");
if (err != 0) {
    std::cout << "Error opening file!" << std::endl; 
}

    Money total = {0, 0}; 
    Money item;
    int g, q;
    short int k;
    char str[10];

    while (fscanf(file, "%s %d %hi %d", &str, &g, &k, &q) == 4) {
    item.grn = g;
    item.kop = k;

    multiply(&item, q);
    add(&total, item);
}

    cout << "Total amount: ";
    Print(&total);

    round(&total);
    cout << "Amount to be paid: ";
    Print(&total);

    fclose(file);
}
