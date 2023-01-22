### Zachariah Magee
#### SD247
#### Jan 20, 2023
# Week 3 Exercises

1. <From section 2.10> 
- Suppose the program counter (PC) is set to 0x2000 0000.
  - a. What range of addresses can be reached using the LEGv8 branch (B) instruction? (In other words, what is the set of possible values for the PC after the branch instruction executes?).
  Branch instructions consist of 6 bits for  the branch instruction and 26 bits for the address field, however, the address field refers to the number of words to the next instruction instead of the number of bytes, which means it can branch +/- 128MB..
   The LEGv8 branch (B) instruction is used to unconditionally jump to a different address. The range of addresses that can be reached using this instruction is the entire set of possible addresses, as the program counter (PC) can be set to any value.
  - b. What range of addresses can be reached using the LEGv8 conditional branch-on-equal (CBZ) instruction? (In other words, what is the set of possible values for the PC after the branch instruction executes?)
  Here the instruction consists of 8 bits, the address is given 19 bits, and the operand address is given 5 bits. The LEGv8 conditional branch-on-equal (CBZ) instruction is used to conditionally jump to a different address based on a comparison. The range of addresses that can be reached using this instruction is also the entire set of possible addresses, as the program counter (PC) can be set to any value if the comparison is true.
---

2. <From section 2.7, 2.10>Consider a proposed new instruction named RPT. This instruction combines a loop's condition check and counter decrement into a single instruction. For example RPT X12, loop would do the following:
```
if (X12 > 0) { X12 = X12 - 1; goto loop }
```
(a) If this instruction were to be added to the ARMv8 instruction set, what is the most appropriate instruction format?
The most appropriate instruction format for the proposed RPT instruction would likely be the I-Type format. This format is typically used for instructions that perform an operation on two registers, one of which is typically the program counter, and an immediate value. The RPT instruction would fit this format well, as it performs an operation on a register (X12) and an immediate value (the loop label), and also updates the program counter.
(b) What is the shortest sequence of LEGv8 instructions that performs the same operation?
The shortest sequence of LEGv8 instructions that performs the same operation as the proposed RPT instruction would be:
```lEGv8
  SUBS X12, X12, #1
  CBNZ X12, loop
```
This sequence uses the SUBS instruction to decrement the value of register X12 by 1 and the CBNZ instruction to perform the conditional branch to the label "loop" if the value in X12 is not equal to zero.

---
3. <From section 2.7>(a) Translate the following loop into C. Assume that the C-level integer i is held in register X10, X0 holds the C-level integer called result, and X1 holds the base address of the integer MemArray. (I know this is your first c program, don't worry about little syntax errors here, it is nearly identifical to how you would write this is Java.)
```LEGv8
    ORR X10, XZR, XZR 
    LOOP: LDUR X11, [X1, #0] 
    ADD X0, X0, X11 
    ADDI X1, X1, #8 
    ADDI X10, X10, #1 
    CMPI X10, 100 
    B.LT LOOP
```

```c
    for (i = 0; i < 100; i++){
        result +=  MemArray[i];
    }
```
  The above LEGv8 assembly code initializes the value of X10 to zero with the ORR instruction. Then it loads the value of the first element of MemArray into X11 using the LDUR instruction, and adds the value of X11 to the value of X0, which holds the C-level integer called result. Then it increments the value of X1 by 8, in order to point to the next element of MemArray. Then it increments the value of X10 by 1, and compares the value of X10 with 100 using the CMPI instruction. If the value of X10 is less than 100, it jumps to the label "LOOP" using the B.LT instruction, otherwise the loop ends.

---

4. <From section 2.3, 2.9> Consider the following code:
```LEGv8
    LDURB X10, [X11, #0] 
    STUR X10, [X11, #8]
```
Assume that the register X11 contains the address 0x10000000 and the data at the address is 0x1122334455667788.

(a) What value is stored in 0x10000008 on a big-endian machine?
  In a big-endian machine, the memory addresses are read from left to right, so the most significant byte of a multi-byte value is stored at the lowest memory address.
  In the given code, the instruction ```LDURB X10, [X11, #0]``` loads the byte at the memory location pointed to by X11 (0x10000000) into the register X10. So, the value in X10 will be 0x88.
  The instruction ```STUR X10, [X11, #8]``` stores the value in the register X10 into memory at the location pointed to by X11 + 8 (0x10000008). So, the value 0x88 will be stored at the memory location 0x10000008.
(b) What value is stored in 0x10000008 on a little-endian machine?
  In a little-endian machine, the instruction ```LDURB``` loads the byte at memory location 0x10000000 (0x88) into register X10, and ```STUR``` instruction stores the content of X10 (0x88) into memory location 0x10000008.
---

5. Assume for a given processor the CPI of arithmetic instructions is 1, the CPI of load/store instructions is 10, and the CPI of branch instructions is 3. Assume a program has the following instruction breakdowns: 500 million arithmetic instructions, 300 million load/store instructions, 100 million branch instructions.
(a) Suppose that new, more powerful arithmetic instructions are added to the instruction set. On average, through the use of these more powerful arithmetic instructions, we can reduce the number of arithmetic instructions needed to execute a program by 25%, while increasing the clock cycle time by only 10%. Is this a good design choice? Why?
   This is a good design choice. By reducing the number of arithmetic instructions needed to execute a program by 25%, while increasing the clock cycle time by only 10%, the total execution time of the program will be reduced. The arithmetic instructions make up 500 million out of the 900 million instructions (500 million / 900 million = 55.56%), so the execution time of the arithmetic instructions is 55.56% of the total execution time. By reducing the number of arithmetic instructions by 25%, the execution time of the arithmetic instructions will be reduced by 25% * 55.56% = 13.89%. Since the clock cycle time is only increased by 10%, the total execution time will be reduced by 13.89% - 10% = 3.89%.
(b) Suppose that we find a way to double the performance of arithmetic instructions. What is the overall speedup of our machine? What if we find a way to improve the performance of arithmetic instructions by 10 time
   If we find a way to double the performance of arithmetic instructions, the overall speedup of our machine would be 2*(1-0.1389) = 1.7612. If we find a way to improve the performance of arithmetic instructions by 10 times, the overall speedup of our machine would be 10*(1-0.1389) = 8.6122.
   So overall performance increases by 1.7612 or 8.6122 times.
   Improvement of arithmetic instruction performance is not the only factor that affects the overall performance of the machine. The performance of other instructions such as load/store and branch also affects the overall performance. The clock cycle time and the CPI of other instructions may also be affected. 
