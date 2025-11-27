#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        // flowerbed
        // adjacent plots cannot be planted
        // 0 -> empty
        // 1 -> full
        // we can place in 0s, but that 0 must not have 1s around it

        int m = flowerbed.size();
        int c = 0;

        for (int i = 0; i < m; i++)
        {

            if (flowerbed[i] == 0)
            {
                bool leftEmpty = false;
                bool rightEmpty = false;
                if (i == 0 || flowerbed[i - 1] == 0)
                    leftEmpty = true;
                if (i == m - 1 || flowerbed[i + 1] == 0)
                    rightEmpty = true;

                if (leftEmpty && rightEmpty)
                {
                    flowerbed[i] = 1;
                    c++;

                    if (c >= n)
                        return true;
                }
            }
        }

        return c >= n;
    }
};