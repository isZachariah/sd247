#include <iostream>
#include <cmath>
#include <bitset>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

auto subHex = [](uint16_t hex1, uint16_t hex2){ return hex1 - hex2; };

// Returns the number of bits required to represent the given value.
int countBits(int value) {
    if (value == 0) {
        return 1;
    }
    return floor(log2(abs(value))) + 1;
}

// Generates all possible logic functions for a variable X with the given constraints.
void generateLogicFunctions(int numBits, bool isSigned, int numZeros, int numOnes) {
    // Determine the number of possible values of X.
    int numValues;
    if (isSigned) {
        numValues = pow(2, numBits - 1);
    } else {
        numValues = pow(2, numBits);
    }

    // Generate all possible values of X and store them in a vector.
    vector<int> values;
    for (int i = 0; i < numValues; i++) {
        values.push_back(i);
    }

    // Filter out values that don't satisfy the constraint on the number of zeros.
    if (numZeros > 0) {
        for (auto it = values.begin(); it != values.end(); ) {
            int numZerosInValue = countBits(*it ^ (*it - 1)) - 1; // count number of 0 bits
            if (numZerosInValue != numZeros) {
                it = values.erase(it);
            } else {
                it++;
            }
        }
    }

    // Filter out values that don't satisfy the constraint on the number of ones.
    if (numOnes > 0) {
        for (auto it = values.begin(); it != values.end(); ) {
            int numOnesInValue;
            if (isSigned && *it < 0) {
                // Handle negative values differently for signed variables.
                numOnesInValue = countBits(~(*it) ^ ((1 << numBits) - 1));
            } else {
                numOnesInValue = countBits(*it);
            }
            if (numOnesInValue != numOnes) {
                it = values.erase(it);
            } else {
                it++;
            }
        }
    }

    // Generate all possible logic functions for X and print them to the console.
    for (int i = 0; i < pow(2, values.size()); i++) {
        bitset<32> bits(i);
        cout << "f(X) = ";
        for (int j = 0; j < values.size(); j++) {
            if (bits[j]) {
                cout << "(X & " << values[j] << ") | ";
            } else {
                cout << "((~X) & " << values[j] << ") | ";
            }
        }
        cout << "0" << endl;
    }
}


int main() {
    int numBits = 3;
    bool isSigned = true;
    int numZeros = 1;  // any number of zeros is allowed
    int numOnes = -1;   // any number of ones is allowed
    generateLogicFunctions(numBits, isSigned, numZeros, numOnes);


    return 0;
}




