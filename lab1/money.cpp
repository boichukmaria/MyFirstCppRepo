#include <iostream>
#include  "money.h"
using namespace std;

void Money::normalize(){
    grn = grn + kop / 100;
    kop = kop % 100;
};

void Money::add(Money other){
    grn = grn + other.grn;
    kop = kop + other.kop;
    normalize();
};

void Money::multiply(int number){
    grn = grn * number;
    kop = kop * number;
    normalize();
};

void Money::round(){
    int specified_rounding = kop % 10; //округлення до 10

    if(specified_rounding < 5){
        kop = kop - specified_rounding;
    } else {
        kop = kop + (10 - specified_rounding);
    };

    normalize();
};

void Money::print(){
    cout << grn << " grn " << kop << " kop" << endl;
};

void lab(){
     ifstream file("input.txt");
    if (!file) return 1; 
    Money total, item;
    int g, q;
    short int k;
    while (file >> g >> k >> q) {
        item = Money(g, k);
        item.multiply(q);
        total.add(item);
    }
    cout << "Total amount: "; total.print();
    total.round();
    cout << "Amount to be paid: "; total.print();
}
