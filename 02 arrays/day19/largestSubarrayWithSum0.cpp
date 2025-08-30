/*
Problem: Find the length of the largest subarray with sum 0.

Time Complexity: O(N)
    - We iterate through the array once → O(N).
    - So total = O(N).

Space Complexity: O(N)
    - We use an unordered_map to store prefix sums and their indices.
    - In worst case, all prefix sums are unique → O(N).
*/

#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> arr)
{
    int n = arr.size();

    unordered_map<int, int> mpp;
    int sum = 0;
    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0) // subarray [0...i] has sum = 0
        {
            maxi = i + 1;
        }
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                maxi = max(maxi, i - mpp[sum]); // length of subarray with sum 0
            }
            else
            {
                mpp[sum] = i; // store first occurrence of this sum
            }
        }
    }
    return maxi;
}

int main()
{
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << "Length of the largest subarray with sum 0: " << maxLen(arr) << endl;

    vector<int> arr2 = {1, 2, -3, 3};
    cout << "Length of the largest subarray with sum 0: " << maxLen(arr2) << endl;

    vector<int> arr3 = {1, 2, 3};
    cout << "Length of the largest subarray with sum 0: " << maxLen(arr3) << endl;

    return 0;
}
