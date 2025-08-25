#include <bits/stdc++.h>
using namespace std;

pair<int, int> findMinAndMax(vector<int> &bloomDay)
{
    int n = bloomDay.size();
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }

    return {mini, maxi};
}

bool findIfPossible(vector<int> &bloomDay, int day, int m, int k)
{
    int n = bloomDay.size();
    int count = 0;
    int totalBouquets = 0;

    for (int i = 0; i < n; i++)
    {
        if (bloomDay[i] <= day)
        {
            count++;
        }
        else
        {
            totalBouquets += (count / k);
            count = 0;
        }
    }
    totalBouquets += (count / k);

    return totalBouquets >= m;
}

// --- Linear Scan ---
int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();

    if (m * k > n)
        return -1;

    pair<int, int> p = findMinAndMax(bloomDay);
    int low = p.first;
    int high = p.second;

    for (int i = low; i <= high; i++)
    {
        if (findIfPossible(bloomDay, i, m, k))
            return i;
    }
    return -1;
}

// --- Binary Search Optimized ---
int minDays2(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();

    if (m * k > n)
        return -1;

    pair<int, int> p = findMinAndMax(bloomDay);
    int low = p.first;
    int high = p.second;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (findIfPossible(bloomDay, mid, m, k))
        {
            ans = mid;
            high = mid - 1; // try smaller day
        }
        else
        {
            low = mid + 1; // need larger day
        }
    }
    return ans;
}

int main()
{
    int n, m, k;
    cout << "Enter number of flowers: ";
    cin >> n;

    vector<int> bloomDay(n);
    cout << "Enter bloom days for each flower:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> bloomDay[i];
    }

    cout << "Enter number of bouquets (m): ";
    cin >> m;
    cout << "Enter flowers needed per bouquet (k): ";
    cin >> k;

    int result1 = minDays(bloomDay, m, k);
    int result2 = minDays2(bloomDay, m, k);

    cout << "\n--- Results ---\n";
    if (result1 == -1)
        cout << "Linear version: Not possible to make " << m << " bouquets.\n";
    else
        cout << "Linear version (minDays): " << result1 << " days\n";

    if (result2 == -1)
        cout << "Binary search version: Not possible to make " << m << " bouquets.\n";
    else
        cout << "Binary search version (minDays2): " << result2 << " days\n";

    return 0;
}
