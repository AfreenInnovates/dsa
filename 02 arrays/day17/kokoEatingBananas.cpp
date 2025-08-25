#include <bits/stdc++.h>
using namespace std;

int findMax(const vector<int> &piles)
{
    int maxVal = INT_MIN;
    for (int x : piles)
        maxVal = max(maxVal, x);
    return maxVal;
}

int calcHours(const vector<int> &piles, int val)
{
    long long totalH = 0;
    for (int x : piles)
    {
        totalH += (x + val - 1) / val;
    }
    return (int)totalH;
}

int minEatingSpeed(const vector<int> &piles, int h)
{
    int low = 1, high = findMax(piles);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int totalHours = calcHours(piles, mid);

        if (totalHours > h)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int n, h;
    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);
    cout << "Enter pile sizes: ";
    for (int i = 0; i < n; i++)
        cin >> piles[i];

    cout << "Enter number of hours: ";
    cin >> h;

    int result = minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl;

    return 0;
}
