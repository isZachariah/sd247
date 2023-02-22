//
// Created by Zachariah Magee on 2/21/23.
//

#include <iostream>

using namespace std;

void halfAdder() {

    int a{0};
    int b{0};

    cout << "Truth Table for Half Adder"   << endl;
    cout << "| A   | B   | C   | S   |\n"
            "|-----|-----|-----|-----|\n"
            "| 0   | 0   | 0   | 0   |\n"
            "| 0   | 1   | 0   | 1   |\n"
            "| 1   | 0   | 0   | 1   |\n"
            "| 1   | 1   | 1   | 0   |\n\n" << endl;


    cout << "Input an integer (A): ";
    cin >> a;
    cout << "Input another integer (B): ";
    cin >> b;

    int s = (a ^ b);
    int c = (a & b);
    int result = ( c << 1 | s);


    cout  << a << " + " << b << endl;
    cout << "s = (a ^ b): " << s << endl;
    cout << "c = (a & b): " << c << endl;
    cout << "result = (c << 1 | s): " << result << endl;

}
