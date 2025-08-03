#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> primeFactors(int num) // function returns a 2D vector like {{2, 3}, {5, 1}}
{
    vector<vector<int>> factors; // 2D empty vector

    // number of times num is divided by 2
    int count = 0;
    while (num % 2 == 0)
    {
        num = num / 2;
        count++;
    }

    if (count > 0)
    {
        factors.push_back({2, count});
    }

    // check for odd factors starting from 3
    for (int i = 3; i * i <= num; i += 2)
    {
        count = 0;
        while (num % i == 0)
        {
            num /= i;
            count++;
        }

        if (count > 0)
            factors.push_back({i, count});
    }

    if (num > 1)
        factors.push_back({num, 1});

    return factors;
}

int maxPower(int n, int k)
{
    vector<vector<int>> factors = primeFactors(k);

    int result = INT_MAX;
}