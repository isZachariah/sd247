// Lab 2 - Problem 2
// Created by Zachariah Magee on 2/21/23.
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Write a program that will read four characters from the keyboard and pack them into a single integer variable.
 * Display the value as hexadecimal.
 * Unpack the four bytes of the variable and output them in reverse order, with the low order byte first.
 * **/
void two() {
    char c1, c2, c3, c4;
    int value;
    //  read four characters from the keyboard
    cout << "Enter four characters: ";
    cin >> c1 >> c2 >> c3 >> c4;

    // pack them into a single integer variable
    value = ((int)c1 << 24) | ((int)c2 << 16) | ((int)c3 << 8) | ((int) c4);

    // Display the value as hexadecimal.
    cout << hex << value << endl;

    // Unpack the four bytes of the variable and output them in reverse order
    cout << "Unpacked bytes in reverse order: ";
    cout << setw(2) << setfill('0') << hex << (value & 0xFF) << " ";
    cout << setw(2) << setfill('0') << hex << ((value >> 8) & 0xFF) << " ";
    cout << setw(2) << setfill('0') << hex << ((value >> 16) & 0xFF) << " ";
    cout << setw(2) << setfill('0') << hex << ((value >> 24) & 0xFF) << endl;
}