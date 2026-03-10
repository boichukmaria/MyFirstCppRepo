#ifndef MONEY_H
#define MONEY_H

struct Money {
    int grn;
    short int kop;
};

void normalize(Money* a);
void add(Money* a, Money other);
void multiply(Money* a, int number);
void round(Money* a);
void print(Money a);

void lab();

#endif