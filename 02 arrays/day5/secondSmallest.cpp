

#include <bits/stdc++.h>
using namespace std;

void bruteApproach(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end()); // O(n log n)

    int smallest = arr[0];
    int sSmallest = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != smallest)
        { // first distinct number after smallest
            sSmallest = arr[i];
            break;
        }
    }

    if (sSmallest == INT_MAX)
        cout << "No second smallest element (all equal)\n";
    else
        cout << "Second smallest (Brute): " << sSmallest << "\n";
}

void betterApproach(vector<int> arr, int n)
{
    int smallest = arr[0];
    int sSmallest = INT_MAX;

    // smallest
    for (auto i : arr)
        if (i < smallest)
            smallest = i;

    // second smallest
    for (auto i : arr)
        if (i != smallest && i < sSmallest)
            sSmallest = i;

    if (sSmallest == INT_MAX)
        cout << "No second smallest element (all equal)\n";
    else
        cout << "Second smallest (Better): " << sSmallest << "\n";
}

void bestApproach(vector<int> arr, int n)
{
    int smallest = arr.at(0);
    int sSmallest = INT_MAX;

    for (auto i : arr)
    {
        if (i < smallest)
        {
            sSmallest = smallest;
            smallest = i;
        }

        else if ((i != smallest) && (i < sSmallest))
        {
            sSmallest = i;
        }
    }

    if (sSmallest == INT_MAX)
        cout << "No second smallest element (all equal)\n";
    else
        cout << "Second smallest (Best): " << sSmallest << "\n";
}

int main()
{
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    int n = arr.size();

    bruteApproach(arr, n);
    betterApproach(arr, n);
    bestApproach(arr, n);

    return 0;
}
