//
// Created by Zachariah Magee on 1/27/23.
//
#include <iostream>
using namespace std;

void swapValues(int &a, int &b){
    int c = b;
    b = a;
    a = c;
}

void callSwapValues(){
    int a,b;
    cout << "Please input two different integers\n";
    cout << "First Integer: ";
    cin  >> a;
    cout << "Second Integer: ";
    cin  >> b;
    cout << "Before swapValues() function\n";
    printf("First Integer (a): %d", a);
    printf("Second Integer (b): %d", b);
    cout << "\n\nSWAPPING VALUES\n\n";
    swapValues(a, b);
    cout << "After swapValues() function\n";
    printf("First Integer (a): %d\n", a);
    printf("Second Integer (b): %d\n\n", b);
}