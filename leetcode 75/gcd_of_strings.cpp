#include <bits/stdc++.h>
#include <numeric>
using namespace std;

// m = str1.size()
// n = str2.size()
// k = min(m,n)
// time = O(k * (m+n))
// worst : O(n × (m + n))
class Solution
{
public:
    int my_gcd(int a, int b)
    {
        while (b != 0)
        {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
    // -------- BRUTE FORCE --------
    string gcdOfStrings_bruteforce(string str1, string str2)
    {

        string s = (str1.size() < str2.size()) ? str1 : str2;

        for (int i = s.size(); i >= 1; i--)
        {
            string subs = s.substr(0, i);

            if (str1.size() % i != 0 || str2.size() % i != 0)
                continue;

            if (!canBuild(str1, subs))
                continue; // move on if can't build
            if (!canBuild(str2, subs))
                continue;

            return subs;
        }

        return "";
    }

    bool canBuild(string full, string piece)
    {
        string temp = "";

        while (temp.size() < full.size())
        {
            temp += piece;
        }
        return temp == full;
    }

    // -------- OPTIMAL  --------
    // If str1 + str2 == str2 + str1, they share the same base pattern.
    // Then the gcd string is the prefix of length gcd(m, n).
    // Time: O(m + n)
    // Space: O(1) extra
    string gcdOfStrings_optimal(string str1, string str2)
    {
        if (str1 + str2 != str2 + str1)
            return "";

        int g = my_gcd((int)str1.size(), (int)str2.size());
        return str1.substr(0, g);
    }
};

int main()
{
    Solution sol;

    string str1, str2;
    cin >> str1 >> str2;

    cout << "Brute Force result: "
         << sol.gcdOfStrings_bruteforce(str1, str2) << endl;

    cout << "Optimal result: "
         << sol.gcdOfStrings_optimal(str1, str2) << endl;

    return 0;
}
