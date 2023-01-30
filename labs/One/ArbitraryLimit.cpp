//
// Created by Zachariah Magee on 1/26/23.
//

//#pragma once

/*
 * Write a program that writes the numbers 1 to an arbitrary limit determined by a user.
 * The program should write the numbers in rows of 10 numbers each, 1 number per column.
 * Do not include numbers that are multiples of 6 or are multiples of 17.*/

#include <iostream>
using namespace std;

void ArbitraryLimit() {
    int limit;
    int count{0};
    cout << "Enter an upper limit: ";
    cin >> limit;
    while(!cin) // or if(cin.fail())
    {   // user didn't input a number
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please input a number for the upper limit: ";
        cin >> limit;
    }
    for (int i = 1; i <= limit; i++) {
        if (i % 6 != 0 || i % 17 != 0){
            cout << i << "\t";
            count++;
            if (count % 10 == 0) {
                cout << endl;
            }
        }
    }
}