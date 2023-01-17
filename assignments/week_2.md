### Zachariah Magee
#### SD247
#### Jan 15, 2023
# Week 2 Exersizes


1. For the following C statement, write the corresponding LEGv8 assembly code.
- Assume that the C variables f, g, and h, have already been placed in registers X0, X1, and X2 respectively.
- Use a minimal number of LEGv8 assembly instructions.
### C:
```c
    f = g + (h - 5);
```
### LEGv8:
```LEGv8
    SUBI x2, x2, #5
    ADD  x0, x1, x3
    
```

---
2. Write a single C statement that corresponds to the two LEGv8 assembly instructions below.
### LEGv8:
```LEGv8
    ADD f, g, h
    ADD f, i, f
```
### C:
```c
    f = g + h + i
```

---
3. For the following C statement, write the corresponding LEGv8 assembly code. 
Assume that the variables f, g, h, i, and j are assigned to registers X0, X1, X2, X3, and X4, respectively.
Assume that the base address of the arrays A and B are in registers X6 and X7, respectively.
  f,   g,  h, i,  and j     A     B
  X0, X1, X2, X3, and X4   X6     X7
### C:
```c
    B[8] = A[i - j];
```
### LEGv8:
```LEGv8
    SUB X9, X3, X4        //X9 = i - j
    LSL X9, X9, #3      
    ADD X11, X6, X9       //X11 = A[i-j]
    LDUR X10, [X11, #0]   //load A[i-j]
    STUR X10, [X7, #64]   //store in B[8]
```
---
4. For the LEGv8 assembly instructions below, what is the corresponding C statement?
- Assume that the variables f, g, h, i, and j are assigned to registers X0, X1, X2, X3, and X4, respectively. 
- Assume that the base address of the arrays A and B are in registers X6 and X7, respectively.

### LEGv8:
```LEGv8
    LSL X9, X0, #3    // X9 = f*8
    ADD X9, X6, X9    // X9 = &A[f]
    LSL X10, X1, #3   // X10 = g*8
    ADD X10, X7, X10  // X10 = &B[g]
    LDUR X0, [X9, #0] // f = A[f]
    ADDI X11, X9, #8
    LDUR X9, [X11, #0]
    ADD X9, X9, X0
    STUR X9, [X10, #0]
```
### C
```c
    f = A[f];
    f = A[f + 1] + A[f];
    B[g] = f;
```
or

```c
    B[g] = A[f] + A[f + 1];
```

---
5. For the LEGv8 assembly instructions above, rewrite the assembly code to minimize the number of LEGv8 instructions needed to carry out the same function.
### LEGv8
```LEGv8
    LSL X9, X0, #3 // X9 = f*8
    ADD X9, X6, X9 // X9 = &A[f]
    LSL X10, X1, #3 // X10 = g*8
    ADD X10, X7, X10 // X10 = &B[g]
    LDUR X0, [X9, #0] // f = A[f]
    LDUR X9, [X11, #8] 
    ADD X9, X9, X0
    STUR X9, [X10, #0]
```
6. Show how the value 0xabcdef12 would be arranged in memory of a little-endian and a big-endian machine. 
Assume the data are stored starting at address 0 and that the word size is 4 bytes.
### Big Endian
- address  |  0  |  1  |  2  |  3
- Byte     | ab  |  cd |  ef |  12
### Little Endian
- address  |  0  |  1  |  2  |  3
- Byte     | 12  |  ef |  cd |  ab


- Translate 0xabcdef12 into decimal.
  10 x 16E7 + 11 x 16E6 + 12 x 16E5 + 13 x 16E4 + 14 x 16E3 + 15 x 16E2 + 1 x 16E1 + 2 x 16E0 
= 2882400018
