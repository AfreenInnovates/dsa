#include <bits/stdc++.h>
using namespace std;

// binary search approach
// time : O(log N)
// space : O(1)
// m is the number
// n is the nth root
// to find: nth root of m
int getNum(int m, int n)
{
    int ans = -1;
    int low = 1, high = m;
    int mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;

        long long val = pow(mid, n);

        if (val == m)
        {
            return mid;
        }
        else if (val > m)
        {
            high = mid - 1;
        }
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int m, n;
    cout << "Enter number (m): ";
    cin >> m;
    cout << "Enter root (n): ";
    cin >> n;

    int result = getNum(m, n);

    cout << n << "th root of " << m << " is: " << result << "\n";

    return 0;
}