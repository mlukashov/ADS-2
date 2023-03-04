// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n==0) 
        return 1;
    return value * pown(value, n - 1);
}

uint64_t fact(uint16_t n) {
    if (n <= 1)
        return n;
    return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double ex = 1;
    for (uint16_t i = 1; i <= count; i++)
        ex = ex + calcItem(x, i);
    return ex;
}

double sinn(double x, uint16_t count) {
    double si = x;
    for (uint16_t i = 1; i <= count; i++)
        si = si + (pown(-1, i - 1) * calcItem(x, 2 * i - 1));
    return si;
}

double cosn(double x, uint16_t count) {
    double co = 1;
    for (uint16_t i = 2; i <= count; i++) 
        co = co + (pown(-1, i - 1) * calcItem(x, 2 * i - 2));
    return co;
}
