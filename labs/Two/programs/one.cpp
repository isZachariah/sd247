// Lab 2 - Problem 1
// Created by Zachariah Magee on 2/21/23
#include <iostream>
#include <cmath>
#include <bitset>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Write a program that prompts a user for input of an integer and store is as an int.
 * Invert all the bits in the value and store the result.
 * Output the original value, the inverted value and the inverted value + 1, each in hexadecimal representation and on one line.
 *  - On the next line, output the same numbers in decimal representation. This should be formatted like table.
 *  - All hexadecimal numbers should be output with leading zeros so eight hexadecimal digits always appear.
 * */
void one() {
    int input;
    cout << "Input an integer: ";
    cin >> input;
    while(!cin) // or if(cin.fail())
    {   // user didn't input a number
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please input a number: ";
        cin >> input;
    }
    int inverted = ~input;

    cout << hex << setfill('0') << setw(8) << input        << ", ";
    cout << hex << setfill('0') << setw(8) << inverted     << ", ";
    cout << hex << setfill('0') << setw(8) << inverted + 1 << endl;

    cout << dec << setfill(' ') << setw(8) << input        << ", ";
    cout << dec << setfill(' ') << setw(8) << inverted     << ", ";
    cout << dec << setfill(' ') << setw(8) << inverted + 1 << endl;
}


