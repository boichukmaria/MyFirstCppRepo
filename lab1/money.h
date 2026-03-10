#ifndef MONEY_H
#define MONEY_H

struct Money {
    int grn;
    short int kop;

    void normalize();
    void add(Money other);
    void multiply(int number);
    void round();
    void print();
};

#endif