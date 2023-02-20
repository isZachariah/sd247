//
// Created by Zachariah Magee on 2/14/23.
//
#include "helpers.h"


int hex_to_decimal(string hex)
{
    int decimal = 0;
    int length = hex.length();
    for (int i = 0; i < length; i++)
    {
        char hex_char = hex[i];
        int value;
        if (hex_char >= '0' && hex_char <= '9')
        {
            value = hex_char - '0';
        }
        else if (hex_char >= 'A' && hex_char <= 'F')
        {
            value = hex_char - 'A' + 10;
        }
        else if (hex_char >= 'a' && hex_char <= 'f')
        {
            value = hex_char - 'a' + 10;
        }
        decimal += value * pow(16, length - i - 1);
    }
    return decimal;
}

void decimal_representation()
{
    string hex_num;
    cout << "Enter a hexadecimal number: ";
    cin >> hex_num;
    int length = hex_num.length();
    int decimal = hex_to_decimal(hex_num);
    bitset<16> binary(decimal);
    cout << "Binary representation: " << binary << endl;

    if (binary[15] == 1)
    {
        int magnitude = 0;
        for (int i = 14; i >= 0; i--)
        {
            if (binary[i] == 1)
            {
                magnitude += pow(2, 14 - i);
            }
        }
        decimal = -magnitude;
        cout << "Decimal representation (sign-magnitude): " << decimal << endl;
    }
    else
    {
        cout << "Decimal representation (sign-magnitude): " << decimal << endl;
    }
}

