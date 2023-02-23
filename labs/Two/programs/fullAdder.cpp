    /*  Write a full adder in c/c++. Use only bitwise operators. Explain in the notes why this works, please be detailed as possible. Include a truth table. */
    #include <iostream>

    using namespace std;

    /* void fullAdder() {
        int a {0b1011};
        int b {0b1100};

        int Cin {0b0001};

        int CarryOut = (a and b) or (b and Cin) or (a and Cin);
        int sum = (a xor b) xor Cin;

        int result = (CarryOut << 1 | sum);

    } */
int full_adder(int a, int b, int c_in) { 
	int sum = a ^ b ^ c_in; // XOR 
	int carry = (a & b) | ((a ^ b) & c_in); // AND, OR, XOR 
	return (carry << 1) | sum; // bit shifting and OR 
}
