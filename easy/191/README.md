# Problem 191 - Number of 1 bits

Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

### Notes

</p>Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.</p>
</p>In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed integer. -3.</p>

### Constraints

<p>The input's binary representation is 32 bits.</p>

### Example 1

```
Input: n = 0000000000000000000000000001011
Output: 3
Explanation: The input binary 00000000000000000000000000001011 has a total of three '1' bits.
```

### Example 2

```
Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary 00000000000000000000000010000000 has a total of one '1' bit.
```

### Example 3

```
Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary 11111111111111111111111111111101 has a total of thirty one '1' bits.
```

## Solutions

Four solutions are presented below.

### Method 1a - Test Every Bit 

<p>Use the bitwise logical *and* operation and a bit mask to evaluate each bit individually. The table below shows the bit masks for an 8 bit number. Bit position 0 is the rightmost bit and corresponds to positional notation of 2^0. The leftmost bit position 7 corresponds to positional notation 2^7. 
</p>


| Bit Position | Bit Mask |
|---|---|
| 0 | 0000 0001 |
| 1 | 0000 0010 |
| 2 | 0000 0100 |
| 3 | 0000 1000 |
| 4 | 0001 0000 |
| 5 | 0010 0000 |
| 6 | 0100 0000 |
| 7 | 1000 0000 |



**Algorithm 1a**

```
let input n be a 32 bit number
let count = 0
let i = 0

while(i < 32)
    let bit mask = 1 left shifted i bit positions
    // is bit in *ith* position is a '1'?
    
    if n logically ANDed with bitmask not equal to zero
        count = count + 1
    i = i + 1

return count
```

### Method 1b - Test all bits until leftmost '1' bit is found 

<p>Test the value of each bit using division by 2 and check the remainder value. Starting from the right, each bit is evaluated to see if it is a '1' or a '0'. Continue moving to the left until the leftmost '1' bit has been evaluated.</p>

<p>For example, when input is 0000 0000 0000 0000 0000 0000 0000 0110, only bits 0-2 will be checked. This is more efficient than the previous method which checked all 32 bits.</p>

```
Example: Let input = 6, binary 0000 0000 0000 0000 0000 0000 0000 0110

6 / 2 = Quotient 3, remainder value is 0. Add zero to one's count.
3 / 2 = Quotient 1, remainder value is 1. Add one to one's count.
1 / 2 = Quotient 0, remainder value is 1. Add one to one's count.
0 / 2 = Quotient 0, remainder value is 0. Add zero to one's count.

If continue testing the remaining 28 bits, the quotient and remainder will always be zero. For efficiency, we stop when the quotient is zero.
```

**Time Complexity** - 0(k) where k is the leftmost bit position. 

Method 1 Algorithm

```
input n
let count = 0
while( n > 0)
    if( n mod 2 equal 1)
        add 1 to count 
    n = n / 2;
return count  
```

### Method 2 - Remove lowest set bits of input n

Algorithm 

```
let n = input value
let count = 0
while(n is not zero)
    add one to count because n must contain at least one '1' bit
    // remove the lowest power one bit
    n = n and (n - 1)
return count
```

```
Examples removing least signifcant '1'

    n = 0xF;        1111
    n - 1 = 0xE;    1110
                    -----
    n & (n-1):      1110        // least significant 1 removed

    n = 0x18;       0001 1000
    n - 1 = 0x17    0001 0111
                    ---------
    n & (n-1):      0001 0000   // least signficant 1 removed
```
    
<p>Time complexity is O(k) where k are the number of bits set to 1. </p>
    
**Why is method 2 better than method 1?**

Method 2 reduces the time complexity of method 1 by not checking the zero bit values.

Example: input n = 1000 0000 0000 0000 0000 0000 0000 0000 

Method 1 time complexity O(32)
Method 2 time complexity O(1)


## Follow Up: 

<p>If this function is called many times, how would you optimize it?</p>

<p>Answer: precompute hamming weights and store them in an array.</p>
