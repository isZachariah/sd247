//
// Created by Zachariah Magee on 1/29/23.
//
#include <iostream>
#include "CircleArea.h"
#include "JobCandidate.h"
#include "ArbitraryLimit.h"
#include "AddressValue.c"
#include "SwapValues.h"
#include "SixIntegers.h"
#include "KeyboardArray.h"

using namespace std;

int main() {
    int selection;
    cout << "Welcome to Zachariah Magee's Lab One for SD247" << endl;
    do {
        cout << "0 - Quit\n"
                "1 - Area Of A Circle\n"
                "2 - Area Of A Circle w/ Precision\n"
                "3 - Job Candidate\n"
                "4 - Arbitrary Limit\n"
                "5 - Keyboard Array\n"
                "6 - Address Value\n"
                "7 - Swap Values\n"
                "8 - Six Integers\n\n"
                "Select a function to run: ";
        cin  >> selection;
        while(!cin || selection < 0 || selection > 8)
        {// user didn't input a number or user didn't input an option
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            cout << "Please input a number between 0-8 to make a selection: ";
            cin >> selection;
        }
        switch (selection){
            case 1: areaOfACircle(); break;
            case 2: precisionAreaOfACircle(); break;
            case 3: isQualified(); break;
            case 4: arbitraryLimit(); break;
            case 5: keyboardArray(); break;
            case 6: addressValue(); break;
            case 7: callSwapValues(); break;
            case 8: sixIntegers(); break;
            default: break;
        }

    } while (selection != 0);

    return 0;
}

