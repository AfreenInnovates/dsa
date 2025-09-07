#include <bits/stdc++.h>
using namespace std;

int countSteps(int x)
{
    int steps = 0;
    while (x > 0)
    {
        x = x / 4;
        steps++;
    }
    return steps;
}

int opsForRange(int left, int right)
{
    int stepSum = 0;
    for (int x = left; x <= right; x++)
    {
        stepSum += countSteps(x);
    }
    return (stepSum + 1) / 2;
}

int main()
{
    vector<vector<int>> queries = {
        {1, 2},
        {2, 4}};

    int totalSteps = 0;

    for (auto query : queries)
    {
        int left = query[0];
        int right = query[1];

        totalSteps += opsForRange(left, right);
    }
    cout << totalSteps << endl;
    return 0;
}