// brute force:
// sort, then start at i = n-2 and go uptil index 0
// if arr[i] != arr[n-1] then secondLargest = arr[i]
// sorting: O(n log (n))
// checking with every element: O(n)
// total time complexity: O(n + n log (n))

// better:
// find the largest : O(n)
// assign sLargest = INT_MIN
// loop through all elements again
// arr[i] > sLargest && sLargest != largest, then we get sLargest : O(n)
// O(n+n) : O(2n)

// best:
// assign largest = arr[0]
// sLargest = INT_MIN
// loop through all elements
// if largest > arr[i]
// sLargest would now be largest
// and largest = arr[i]

#include <bits/stdc++.h>
using namespace std;

void bruteApproach(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end());
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] != arr[n - 1])
        {
            cout << "Second largest: " << arr[i] << endl;
            return;
        }
    }
}

void betterApproach(vector<int> arr, int n)
{
    int largest = arr.at(0);
    int sLargest = INT_MIN;

    for (auto i : arr)
    {
        if (i > largest)
        {
            largest = i;
        }
    }

    for (auto i : arr)
    {
        if ((i > sLargest) && (i != largest))
        {
            sLargest = i;
        }
    }
    cout << "Second largest: " << sLargest << endl;
    return;
}

void bestApproach(vector<int> arr, int n)
{
    int largest = arr.at(0);
    int sLargest = INT_MIN;

    for (auto i : arr)
    {
        if (i > largest)
        {
            sLargest = largest;
            largest = i;
        }
    }

    if (sLargest == INT_MIN)
        cout << "No second largest element\n";
    else
        cout << "Second largest: " << sLargest << endl;
}

int main()
{
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    int n = arr.size();

    cout << "Brute Force Approach: ";
    bruteApproach(arr, n);

    cout << "Better Approach: ";
    betterApproach(arr, n);

    cout << "Best Approach: ";
    bestApproach(arr, n);

    return 0;
}
