#include <bits/stdc++.h>
using namespace std;

vector<int> usingSTL(vector<int> &nums)
{
    next_permutation(nums.begin(), nums.end());
    return nums;
}