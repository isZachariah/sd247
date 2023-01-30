//
// Created by Zachariah Magee on 1/25/23.
//

#include <iostream>
#include <cmath>
#include <iomanip>

#include "CircleArea.h"

using namespace std;

void areaOfACircle() {
    double radius, area;
    cout << "Enter the radius of the circle: ";
    cin  >> radius;
    while(!cin) // or if(cin.fail())
    {   // user didn't input a number
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please input a number for the radius of the circle: ";
        cin >> radius;
    }
    area = M_PI * pow(radius, 2);
    cout << "The area of the circle is: " << area << endl;
}

void precisionAreaOfACircle() {
    int precision;
    double radius, area;
    cout << "Enter the precision for the area of the circle: ";
    cin  >> precision;
    while(!cin)
    {// user didn't input a number
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
        cout << "Please input a number for the precision: ";
        cin >> precision;
    }
    cout << "Enter the radius of the circle: ";
    cin  >>  radius;
    while(!cin)
    {  // user didn't input a number
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please input a number for the radius of the circle: ";
        cin >> radius;
    }
    area = M_PI * pow(radius, 2);
    cout << "The area of the circle is: " << fixed << setprecision(precision) <<  area << endl;
}

