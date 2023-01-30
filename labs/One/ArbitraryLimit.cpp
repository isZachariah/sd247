//
// Created by Zachariah Magee on 1/26/23.
//
#include <iostream>
using namespace std;

void arbitraryLimit() {
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