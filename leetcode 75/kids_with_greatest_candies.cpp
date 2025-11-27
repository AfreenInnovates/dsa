#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        // n kids with candies
        // candies array ->
        // candies[i] = number of candies ith kid has
        // extrCandies -> no. of extra candies that I have

        // get the greatest candy among kids
        int mx = 0;
        for (int x : candies)
        {
            mx = max(mx, x);
        }

        vector<bool> res;

        // compare the max value with every other value, and then push back true / false if giving the candies would make them the highest
        for (int x : candies)
        {
            x = x + extraCandies;
            if (x >= mx)
                res.push_back(true);
            else
                res.push_back(false);
        }

        return res;
    }
};