#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Count how many 1-bits are in x (binary form).
    // Example: x = 13 (1101b) -> returns 3
    static int bitCount(unsigned long long x)
    {
        return __builtin_popcountll(x); // works on most compilers
        // (If you're on C++20, you can use: return std::popcount(x); with #include <bit>)
    }

public:
    int makeTheIntegerZero(int num1, int num2)
    {
        // We try k = 1, 2, 3, ... operations.
        // After k operations, the remaining number is:
        //     x = num1 - k * num2
        // We want x to be expressible as a sum of exactly k powers of two (like 4=2+2).
        //
        // Two necessary rules for this to be possible:
        // 1) x must be >= 0 (you can't make a positive sum equal a negative number).
        // 2) You need at least as many terms as the number of 1-bits in x:
        //       bitCount(x) <= k
        //    (Because every 1-bit needs at least one power-of-two term.)
        // Also, the smallest sum of k positive powers of two is k (k * 1),
        // so x must also be >= k. We check that early to bail out if impossible.

        // Special case: if num2 == 0, each operation only "removes" one power of two.
        // So the minimum operations needed is just the count of 1-bits in num1.
        if (num2 == 0)
        {
            return bitCount((unsigned long long)((long long)num1));
        }

        long long x = num1; // use 64-bit to be safe while subtracting repeatedly

        // Try k from 1 up to 60 (60 is plenty for 64-bit ranges)
        for (int k = 1; k <= 60; k++)
        {
            x -= num2; // x now equals num1 - k * num2

            // If x < k, then it's impossible from now on:
            // - x will keep going down each loop (subtracting num2),
            // - k is going up,
            // so x < k will only get worse. We can stop with -1.
            if (x < k)
                return -1;

            // Check if x can be written as a sum of k powers of two:
            // - x must be >= 0
            // - number of 1-bits in x must be <= k
            if (x >= 0 && k >= bitCount((unsigned long long)x))
            {
                return k; // first k that works is the answer
            }
        }
        return -1; // No k in [1..60] worked
    }
};

/*
=============================================
DRY RUNS (Step-by-step) — written as comments
=============================================

Legend:
- k  : number of operations we are trying
- x  : num1 - k * num2 after subtracting in the loop
- bc : bitCount(x) = number of 1-bits in x
- Checks:
    A) x < k ?  (if yes -> return -1)
    B) x >= 0 AND k >= bc ? (if yes -> return k)

-------------------------------------------------
Example 1: num1 = 10, num2 = 3
Start: x = 10 (before loop)

k = 1:
    x = 10 - 3 = 7
    A) 7 < 1 ?  no
    bc = bitCount(7) = bitCount(0b111) = 3
    B) x >= 0 (true) AND k >= bc ?  1 >= 3 ? no -> continue

k = 2:
    x = 7 - 3 = 4
    A) 4 < 2 ?  no
    bc = bitCount(4) = bitCount(0b100) = 1
    B) x >= 0 (true) AND k >= bc ?  2 >= 1 ? yes
    => return 2

Answer: 2


-------------------------------------------------
Example 2: num1 = 5, num2 = 2
Start: x = 5

k = 1:
    x = 5 - 2 = 3
    A) 3 < 1 ?  no
    bc = bitCount(3) = bitCount(0b11) = 2
    B) 1 >= 2 ? no -> continue

k = 2:
    x = 3 - 2 = 1
    A) 1 < 2 ?  yes
    => return -1 (we can stop; it'll only get worse)

Answer: -1


-------------------------------------------------
Example 3 (special case): num1 = 13, num2 = 0
- We take the if-branch and return bitCount(13)
- 13 in binary = 1101 (three 1-bits) -> return 3

Answer: 3


======================
Time & Space Complexity
======================
Time: O(60) = O(1)  // fixed small loop, constant-time bitCount on 64-bit
Space: O(1)         // only a few integers used
*/
