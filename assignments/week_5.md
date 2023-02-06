# Week 5 Exercises
---

NOTE: I didn't get to all of the problems this week.

---
1. What is 5ED4 - (minus) 07A4 when these values represent unsigned 16-bit hexadecimal numbers? The result should be written in hexadecimal. Show your work.
  - First I created this function:
```c++
    auto subHex = [](uint16_t hex1, uint16_t hex2){ return hex1 - hex2; };
```
- Then I used it:
```c++
    printf("0x%x", subHex(0x5ED4, 0x07A4));
```
- by hand:
```    
    5ED4    
   -07A4
          4 - 4 = 0
D - A = 13 - 10 = 3
E - 7 = 14 - 14 = 7
          5 - 0 = 5
                    = 5730 
```
- This was my result: 0x5730
---
2. What is 5ED4 - (minus) 07A4 when these values represent signed 16-bit hexadecimal numbers stored in sign-magnitude format? The result should be written in hexadecimal. Show your work.
    - Neither MSB is 1, so the result is exactly the same. 0x5730
    - hexadecimal number: 5ED4
    - Binary representation: 0101111011010100
    - Decimal representation (sign-magnitude): 24276
    - hexadecimal number: 07A4
    - Binary representation: 0000011110100100
    - Decimal representation (sign-magnitude): 1956
---
3. Convert 5ED4 into a binary number. What makes base 16 (hexadecimal) an attractive numbering system for representing values in computers
   - Binary representation: 0101111011010100
   - One hex digit is the direct equivalent to 4 binary bits making it incredibly easy to navigate and convert between the two.
---
4. Assume 185 and 122 are signed 8-bit decimal integers stored in sign-magnitude format. Calculate 185 - 122. Is there overflow, underflow, or neither?
```
   185(-71)    ->      1011 1001
   -122        ->     -1000 0110
   -----------------------------
    -193(65)   ->      0011 0101 
```
   - yes there is overflow because the lowest possible negative number is -128
---
5. Assume 151 and 214 are signed 8-bit decimal integers stored in two's complement format. Calculate 151 + 214 using saturating arithmetic. The result should be written in decimal. Show your work.
```
151 - 214; in saturating arithmetic will be represented by 01111111 + 1111111. This will add up to 00000000 or zero.
```
**Answer: 0**

---
6. Calculate the time necessary to perform a multiply using the approach given in COD Figure 3.3 (First version of the multiplication hardware) and 3.4 (The first multiplication algorithm, using the hardware shown in COD Figure 3.3) if an integer is 8 bits wide and each step of the operation takes four time units. Assume that in step 1a an addition is always performed—either the multiplicand will be added, or a zero will be. Also assume that the registers have already been initialized (you are just counting how long it takes to do the multiplication loop itself). If this is being done in hardware, the shifts of the multiplicand and multiplier can be done simultaneously. If this is being done in software, they will have to be done one after the other. Solve for each case.
---
7. Calculate the time necessary to perform a multiply using the approach described in the text (31 adders stacked vertically) if an integer is 8 bits wide and an adder takes four time units.
---
8. Calculate the time necessary to perform a multiply using the approach given in COD Figure 3.7 (Fast multiplication hardware) if an integer is 8 bits wide and an adder takes four time units.
---
9. As discussed in the text, one possible performance enhancement is to do a shift and add instead of an actual multiplication. Since 9 × 6, for example, can be written (2 × 2 × 2 + 1) × 6, we can calculate 9 × 6 by shifting 6 to the left three times and then adding 6 to that result. Show the best way to calculate 0 × 33 × 0 × 55 using shifts and adds/subtracts. Assume both inputs are 8-bit unsigned integers.
---
10. Using a table similar to that shown in COD Figure 3.10 (Division example using the algorithm in COD Figure 3.9), calculate 60 divided by 17 using the hardware described in COD Figure 3.8 (First version of the division hardware). You should show the contents of each register on each step. Assume both inputs are unsigned 6-bit integers.
---
11. What decimal number does the bit pattern 0×0C000000 represent if it is a floating point number? Use the IEEE 754 standard
```
   1.046874 * 2 ^ -116
```
---
12. Write down the binary representation of the decimal number 63.25 assuming the IEEE 754 single precision format.
```
   63 = 111111
   0.25 = 0.01
   63.25 = 111111.01
   
   IEEE 754 single precision format:
   0-10000100-11111010000000000000000
```
---
13. Using the IEEE 754 floating point format, write down the bit pattern that would represent -1/4. Can you represent -1/4 exactly?
```
   - 1/4 = -2^(-2) = -0.01
   0.01 = 1 * 2^(-2) = 1 * 2^(125-127)
   sign = 1
   exponent = 125 = 0111 11011 
   0111 1101 000 0000 0000 0000 0000 0000
```
---
16. Write down the bit pattern in the fraction of value 1/3 assuming a floating point format that uses binary numbers in the fraction. Assume there are 24 bits, and you do not need to normalize. Is this representation exact?
