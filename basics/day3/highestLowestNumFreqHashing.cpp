#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, int> mpp;

    int n;
    cout << "Enter length of array: ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter number: ";
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]] += 1;
    }

    int maxEle = 0, maxCount = 0, minEle = 0, minCount = INT_MAX;

    for (auto it : mpp)
    {
        int ele = it.first;
        int count = it.second;

        if (count > maxCount)
        {
            maxCount = count;
            maxEle = ele;
        }

        if (count < minCount)
        {
            minCount = count;
            minEle = ele;
        }
    }

    cout << "The element with minimum number of counts is " << minEle << " with a count of " << minCount << endl;
    cout << "The element with maximum number of counts is " << maxEle << " with a count of " << maxCount << endl;
}