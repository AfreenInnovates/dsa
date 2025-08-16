#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(1)
int approach1(int arr[], int n, int k)
{
    int maxLength = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (sum == k)
            {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}

// Sliding window approach (works only for non-negative numbers)
// Time Complexity: O(n)
// Space Complexity: O(1)
int approach2(int arr[], int n, int k)
{
    int left = 0, right = 0;
    int maxLen = 0;
    long long sum = arr[0];

    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }

        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < n)
            sum += arr[right];
    }

    return maxLen;
}

int main()
{
    int arr[] = {1, 2, 3, 1, 1, 1, 5, -1, 6};
    int k = 6;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Approach 1 (Brute Force) -> Max length: "
         << approach1(arr, n, k) << endl;

    cout << "Approach 2 (Sliding Window) -> Max length: "
         << approach2(arr, n, k) << endl;

    return 0;
}
