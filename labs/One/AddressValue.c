//
// Created by Zachariah Magee on 1/27/23.
//
#include "stdio.h"

void addressValue(){
    char  c[10] = "zachariah";
    int    i = 47;
    double d = 1.02;

    printf("double address: %p\ndouble value: %f\n", &d, d);
    printf("int address: %p\nint value: %i\n", &i, i);
    printf("string address: %p\nstring value: %s", &c, c);
}