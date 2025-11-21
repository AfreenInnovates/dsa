#include <bits/stdc++.h>
using namespace std;

// approach 1
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string res = "";

        int i = 0, j = 0;

        int n1 = word1.size(), n2 = word2.size();

        if (n1 < n2)
        {
            while (i < n1)
            {
                res += word1[i];
                res += word2[j];
                i++;
                j++;
            }
            while (j < n2)
            {
                res += word2[j];
                j++;
            }
        }
        else
        {
            while (j < n2)
            {
                res += word1[i];
                res += word2[j];
                i++;
                j++;
            }

            while (i < n1)
            {
                res += word1[i];
                i++;
            }
        }
        return res;
    }
};

// approach 2:
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string res = "";

        int i = 0, j = 0;

        int n1 = word1.size(), n2 = word2.size();

        while (i < n1 && j < n2)
        {
            res += word1[i];
            res += word2[j];

            i++;
            j++;
        }

        while (i < n1)
        {
            res += word1[i];
            i++;
        }

        while (j < n2)
        {
            res += word2[j];
            j++;
        }

        return res;
    }
};