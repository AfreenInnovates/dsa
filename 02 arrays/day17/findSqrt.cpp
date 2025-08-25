#include <bits/stdc++.h>
using namespace std;

// Linear approach
// time : O(root(x))
// space : O(1)
int mySqrtLinear(int x)
{
    int ans = 0;
    for (long long i = 1; i * i <= x; i++)
    {
        ans = i;
    }
    return ans;
}

// Binary search approach
// time : O(log(N))
// space : O(1)
int mySqrtBinary(int n)
{
    int ans = 0;
    int low = 0, high = n, mid = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;
        long long sq = 1LL * mid * mid; // prevent overflow

        if (sq <= n)
        {
            ans = mid;     // mid is a candidate
            low = mid + 1; // look for bigger
        }
        else
        {
            high = mid - 1; // look for smaller
        }
    }
    return ans;
}

int main()
{
    vector<int> testCases = {0, 1, 4, 8, 10, 16, 25, 2147395599};

    cout << "Testing Square Root Approaches:\n";
    for (int x : testCases)
    {
        cout << "x = " << x << "\n";
        cout << "  Linear sqrt:  " << mySqrtLinear(x) << "\n";
        cout << "  Binary sqrt:  " << mySqrtBinary(x) << "\n";
        cout << "-------------------\n";
    }

    return 0;
}
