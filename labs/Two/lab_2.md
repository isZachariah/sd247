# Lab Two

1. Write a program that prompts a user for input of an integer and store is as an int. Invert all the bits in the value and store the result. Output the original value, the inverted value and the inverted value + 1, each in hexadecimal representation and on one line.
   - On the next line, output the same numbers in decimal representation. This should be formatted like table.
   - All hexadecimal numbers should be output with leading zeros so eight hexadecimal digits always appear.
   - [Solution to Problem One](programs/one.cpp)
```c++
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
```
2. Write a program that will read four characters from the keyboard and pack them into a single integer variable. Display the value as hexadecimal. Unpack the four bytes of the variable and output them in reverse order, with the low order byte first.
   - [Solution to Problem Two](programs/two.cpp)
```c++
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
```

---

3. Write a half adder in c/c++ to sum to ints. This should sum and carry. Use only bitwise operators. Explain in the notes why this works, please be detailed as possible. Include a truth table.
 
| A   | B   | C   | S   |
|-----|-----|-----|-----|
| 0   | 0   | 0   | 0   |
| 0   | 1   | 0   | 1   |
| 1   | 0   | 0   | 1   |
| 1   | 1   | 1   | 0   |

- [Half Adder console program](programs/halfAdder.cpp)
- example:
```cpp
int a = 0b100111;
int b = 0b110110;
int s = (a ^ b);
int c = (a & b);
int result = ( c << 1 | s);
```

---

5. Write a full adder in c/c++. Use only bitwise operators. Explain in the notes why this works, please be detailed as possible. Include a truth table. 

---

6. Write a multiplication program that only uses bitwise operators. Explain in the notes why this works, please be detailed as possible. 
