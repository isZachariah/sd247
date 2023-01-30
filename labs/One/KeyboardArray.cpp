//
// Created by Zachariah Magee on 1/27/23.
//
#pragma once
/* Write a program that reads an array size from the keyboard and dynamically allocates an array of that size for floating-point values.
 * Using pointer notation, initialize all the elements of the array so that the value is the index position n, 1/(n+1)^2.
 * Calculate the sum of the elements using array notation, and then output the square root of that sum.
 * */
#include "iostream"
#include "cmath"

using namespace std;

void keyboardArray(){
    int size;
    cout << "Enter the size for an array: ";
    cin  >> size;
    while(!cin)
    {// user didn't input a number
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please input a number for the size of the array: ";
        cin >> size;
    }
    float arr[size];
    float *p = arr; float sum{0};
    for (auto n = 0; n < size; n++){
        p[n] = (float)pow((1.0/(n+1.0)),2);
        sum += arr[n];
    }
    cout << sqrt(sum) << endl;
}