# Week 6 Exercises

1. In addition to the basic laws we discussed in this section, there are two important theorems, called DeMorgan's theorems. Prove DeMorgan's theorems with a truth table of the form
  -  The two De Morgan's theorems are:
   1. The complement of the union of two sets is equal to the intersection of their complements:
```
~(A OR B) = ~A AND ~B

```
   2. The complement of the intersection of two sets is equal to the union of their complements:
```
~(A OR B) = ~A AND ~B
```

| A   | B   | A OR B | ~A  | ~B  | ~A AND ~B | ~(A AND B) |
|-----|-----|--------|-----|-----|-----------|------------|
| 0   | 0   | 0      | 1   | 1   | 1         | 1          |
| 0   | 1   | 1      | 1   | 0   | 0         | 0          |
| 1   | 0   | 1      | 0   | 1   | 0         | 0          |
| 1   | 1   | 1      | 0   | 0   | 0         | 0          |


| A   | B   | A OR B | ~A  | ~B  | ~A AND ~B | ~(A AND B) |
|-----|-----|--------|-----|-----|-----------|------------|
| 0   | 0   | 0      | 1   | 1   | 1         | 1          |
| 0   | 1   | 0      | 1   | 0   | 1         | 1          |
| 1   | 0   | 0      | 0   | 1   | 1         | 1          |
| 1   | 1   | 1      | 0   | 0   | 0         | 0          |

---
2. One logic function that is used for a variety of purposes (including within adders and to compute parity) is exclusive OR. The output of a two-input exclusive OR function is true only if exactly one of the inputs is true. Show the truth table for a two-input exclusive OR function and implement this function using AND gates, OR gates, and inverters.

| A   | B   | XOR |
|-----|-----|-----|
| 0   | 0   | 0   |
| 0   | 1   | 1   |
| 1   | 0   | 1   |
| 1   | 1   | 0   |


```
XOR = (A AND ~B) OR (~A AND B)
```
![XOR](logicGates/XOR.png)
![XOR_2](logicGates/XOR_2.png)


---
3. Assume that X consists of 3 bits, x2 x1 x0. Write four logic functions that are true if and only if

- X contains only one 0
```
f(X) = (x2 AND x1 AND ~x0) OR (x2 AND ~x1 AND x0) OR (~x2 AND x1 AND x0)
f(X) = (x2 AND ~x1 AND ~x0) OR (~x2 AND x1 AND ~x0) OR (~x2 AND ~x1 AND x0)
```
- X contains an even number of 0s
```
f(X) = (x2 AND ~x1 AND ~x0) OR (~x2 AND ~x1 AND x0) OR (~x2 AND x1 AND ~x0) OR (~x2 AND ~x1 AND ~x0)
```
- X when interpreted as an unsigned binary number is less than 4
```
f(X) = ~x2 AND ~x1 AND x0
```

- X when interpreted as a signed (two's complement) number is negative
```
f(X) = x2 AND ~x1 AND ~x0
```

---
4. Assume that X consists of 3 bits, x2 x1 x0, and Y consists of 3 bits, y2 y1 y0. Write logic functions that are true if and only if

- X < Y, where X and Y are thought of as unsigned binary numbers
```
f(X, Y) = (~x2 AND y2) OR ((~x2 AND ~y2) AND (x1 AND ~y1 AND (x0 AND ~y0)))
f(X, Y) = (x2 AND ~y2) OR ((x2 = y2) AND ((x1 AND ~y1) OR ((x1 = y1) AND (x0 AND ~y0))))
```
- X < Y, where X and Y are thought of as signed (two's complement) numbers
```
f(X, Y) = (x2 AND ~y2) OR ((x2 AND y2) AND (x1 < y1 OR (x1 = y1 AND x0 < y0)))
```
- X = Y
```
f(X, Y) = (x2 = y2) AND (x1 = y1) AND (x0 = y0)
```
5. Use a hierarchical approach that can be extended to larger numbers of bits. Show how can you extend it to 6-bit comparison.

- One hierarchical approach for comparing two binary numbers is to compare their most significant bits (MSBs) first. If the MSBs are equal, then we compare the second most significant bits, and so on, until we find a pair of bits that are not equal. The number with the larger bit at that position is the larger number overall.

- To extend this approach to 6-bit comparison, we can use the following algorithm:

    1. Compare the MSBs (the 6th bits) of the two numbers.
    2. If the MSBs are equal, compare the second most significant bits (the 5th bits) of the two numbers.
    3. If the 5th bits are equal, compare the third most significant bits (the 4th bits) of the two numbers.
    4. If the 4th bits are equal, compare the fourth most significant bits (the 3rd bits) of the two numbers.
    5. If the 3rd bits are equal, compare the fifth most significant bits (the 2nd bits) of the two numbers.
    6. If the 2nd bits are equal, compare the least significant bits (the 1st bits) of the two numbers.
    7. The number with the larger bit at the first unequal position is the larger number overall.

| A[i] | B[i] | C[i] |
|------|------|------|
|      |      |      |
|      |      |      |



---
6. Show a truth table for a multiplexor (inputs A, B, and S; output C), using don't cares to simplify the table where possible.

| S   | B   | A   | C                 |
|-----|-----|-----|-------------------|
| 0   | 0   | 0   | A                 |
| 0   | 0   | 1   | A                 |
| 0   | 1   | 0   | B                 |
| 0   | 1   | 1   | B                 |
| 1   | 0   | 0   | 0 or "don't care" |
| 1   | 0   | 1   | 1 or "don't care" |
| 1   | 1   | 0   | 0 or "don't care" |
| 1   | 1   | 1   | 1 or "don't care" |

- Simplified:

| S   | B   | A   | C   |
|-----|-----|-----|-----|
| 0   | 0   | 0   | A   |
| 0   | 0   | 1   | A   |
| 0   | 1   | 0   | B   |
| 0   | 1   | 1   | B   |


In the truth table above, the output C depends on the select signal S. When S is 0, the output C is either A or B, depending on the values of the inputs A and B. When S is 1, the output C can be either 0 or 1, but its value does not depend on the input values of A and B. The "don't care" values in the truth table indicate that the output value can be either 0 or 1 in these cases, and can be chosen to simplify the circuit implementation.

The output C depends on the select signal S, and the input values A and B only matter when S is 0. When S is 1, the output C can be either 0 or 1, regardless of the input values of A and B. 

When the select signal S is 0, the MUX is said to be in "data mode", meaning that it is selecting one of the two data inputs (A or B) to pass through to the output. When S is 1, the MUX is said to be in "control mode", meaning that it is not passing any data through, and the output is either 0 or 1, depending on the implementation.

In some cases, the output value in control mode may be fixed at 0 or 1, while in other cases, it may be allowed to vary (i.e., it may be a "don't care" value). The specific implementation of the MUX will depend on the requirements of the system in which it is being used.