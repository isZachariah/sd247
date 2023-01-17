# Exercises
Submit the following exercises in section 1.13 as HW. 

- Describe the steps that transform a program written in a high-level language such as C into a representation that is directly executed by a computer processor.

Once the high level code has been written by a programmer, it is then built/ compiled into assembly language which is a list of instruction statements, the assembler then translates assembly language into machine code (a binary representation of assembly language). Collections of bits add up to messages that create instructions for the computer to follow. Unlike our base10 numeric system, binary only contains 0 and 1 or on and off - and luckily this is the language that a computer speaks, electrical signals.

---

- Assume a color display using 8 bits for each of the primary colors (red, green, blue) per pixel and a frame size of 1280 × 1024.

(a) What is the minimum size in bytes of the frame buffer to store a frame?
**3.93216Mb**
(b) How long would it take, at a minimum, for the frame to be sent over a 100 Mbit/s network?
**0.3145728s**

- Consider three different processors P1, P2, and P3 executing the same instruction set. 
- P1 has a 3.0 GHz clock rate and a CPI of 1.5.
- P2 has a 2.5 GHz clock rate and a CPI of 1.0. 
- P3 has a 4.0 GHz clock rate and has a CPI of 2.2.

    P1 = 3 GHz   / 1.5 = 2,000,000,000
    P2 = 2.5 GHz / 1.0 = 2,500,000,000
    P3 = 4 GHz   / 2.2 = 1,818,181,818

(a) Which processor has the highest performance expressed in instructions per second? **P2**

(b) If the processors each execute a program in 10 seconds, find the number of cycles and the number of instructions.
    **P1: Clock cycles = 3 x 10¹⁰   or 30,000,000,000   - #instructions = 2 x 10¹⁰     or 20,000,000,000**
    **P2: Clock cycles = 2.5 x 10¹⁰ or 25,000,000,000   - #instructions = 2.5 x 10¹⁰   or 25,000,000,000**
    **P3: Clock cycles = 4 x 10¹⁰   or 40,000,000,000   - #instructions = 1.82 x 10¹⁰  or 18,200,000,000**

(c) We are trying to reduce the execution time by 30% but this leads to an increase of 20% in the CPI. What clock rate should we have to get this time reduction?
    **clock rate (new) for P1 = 3 GHz x 1.71   = 5.13 GHz**
    **clock rate (new) for P2 = 2.5 GHz x 1.71 = 4.27 GHz**
    **clock rate (new) for P3 = 4.0 GHz x 1.71 = 6.84 GHz**

- COD Section 1.10 (Fallacies and pitfalls) cites as a pitfall the utilization of a subset of the performance equation as a performance metric. To illustrate this, consider the following two processors. P1 has a clock rate of 4 GHz, average CPI of 0.9, and requires the execution of 5.0E9 instructions. P2 has a clock rate of 3 GHz, an average CPI of 0.75, and requires the execution of 1.0E9 instructions.

(a) One usual fallacy is to consider the computer with the largest clock rate as having the highest performance. Check if this is true for P1 and P2.

    |Processor|   Clock Rate |  CPI  | Instructions|
    |_________|______________|_______|_____________|
    |   P1    |     4 GHz    |  0.9  |      5.0E9  |
    |   P2    |     3 GHz    |  0.75 |      1.0E9  |
    
    performance equation:
    
    CPU Time = instruction count * average cycles per instruction/ clock rate
    
    CPU Time = I * CPI / clock rate
    
    Where instruction count refers to the number of instructions.
    
    Performance of P1:
    
    CPU Time (P1) = 5 * 10^9 * 0.9 / (4 * 10^9 )
                            = 5000000000 * 0.9 / 4000000000
                            = 4500000000 / 4000000000
                            =  1.125s
    
    Performance of P2:
    
    CPU Time (P2) = 10^9 * 0.75/ ( 3 * 10^9 )
                            = 750000000 / 3000000000
                            = 0.25s
    
    So the Performance of P2 is larger than that of P1,
     performance (P2) > performance (P1)
         0.25 is better than 1.125
    
    But clock rate of P1 was larger than P2
     clock rate of P1 > clock rate of P2
          4 GHz > 3 GHz

**So this is a misconception about P1 and P2. A computer with the largest clock rate does not necessarily have the highest  performance.**

(b) Another fallacy is to consider that the processor executing the largest number of instructions will need a larger CPU time. Considering that processor P1 is executing a sequence of 1.0E9 instructions and that the CPI of processors P1 and P2 do not change, determine the number of instructions that P2 can execute in the same time that P1 needs to execute 1.0E9 instructions.
with only 75% of the clock rate P1 has P2 can do 90% of the instructions P1 can do
**900,000,000 instructions**


(c) A common fallacy is to use MIPS (millions of instructions per second) to compare the performance of two different processors, and consider that the processor with the largest MIPS has the largest performance. Check if this is true for P1 and P2.
    P1 MIPS = (4 * 10^9 * 10^-6) / .9 = 4,444.44
    P2 MIPS = (3 * 10^9 * 10^-6) / .75 = 4,000
**P1 has greater MIPS but P2 still has greater performance**

(d) Another common performance figure is MFLOPS (millions of floating-point operations per second), defined as MFLOPS = No. FP operations / (execution time × 1E6) but this figure has the same problems as MIPS. Assume that 40% of the instructions executed on both P1 and P2 are floating-point instructions. Find the MFLOPS figures for the processors.


|Processor|   Clock Rate |  CPI  | FP Instructions | Instructions|
|_________|______________|_______|_________________|_____________|
|   P1    |     4 GHz    |  0.9  |     2.0E9       |      3.0E9  |
|   P2    |     3 GHz    |  0.75 |     4.0E9       |      6.0E9  |

MFLOPS = No. FP operations / (execution time × 1E6)

P1 MFLOPS = (2 * 10^9) / (1.125s * 10^6) = 1,777.777...
P2 MFLOPS = (4 * 10^8) /(.25 * 10^6) = 1,600

**P1 does a larger number of MFLOPS but still P2 has greater performance**

- Another pitfall cited in COD Section 1.10 (Fallacies and pitfalls) is expecting to improve the overall performance of a computer by improving only one aspect of the computer. Consider a computer running a program that requires 250 s, with 70 s spent executing FP instructions, 85 s executed L/S instructions, and 40 s spent executing branch instructions.
  Consider a computer running a program that requires
TIME: 250s
FPI: 70s 
L/S I: 85s 
Br I: 40s

(a) By how much is the total time reduced if the time for FP operations is reduced by 20%?
**0.8 * 70s = 56s | 236s total = reduced by 14s**

(b) By how much is the time for INT operations reduced if the total time is reduced by 20%?
0.8 * 250s = 200s
200 - 70 - 80 - 40 = 5s
250 - 70 - 80 - 40 = 55s
5/55 = 0.091 = **91%**

(c) Can the total time can be reduced by 20% by reducing only the time for branch instructions?
55 + 70 + 85 = 205
205 / 255 = 82% **no**