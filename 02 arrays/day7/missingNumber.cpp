#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force (Nested Loop)
- Time Complexity: O(n^2)
    For each number from 1 to n, we do a linear search in the array of size (n-1) --> O(n*(n-1)) = O(n^2 - n) = O(n^2)
- Space Complexity: O(1)
    No extra space used
*/
int approach1(vector<int> arr, int n)
{
    for (int i = 0; i <= n; i++)
    {
        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                found = true;
                break;
            }
        }
        if (!found)
            return i;
    }
    return -1;
}

/*
Approach 2: Sorting-Based
- Time Complexity: O(n log n) + O(n)
    Sorting takes O(n log n), linear scan to find missing element takes O(n)
- Space Complexity: O(1) (or O(n) if sort uses additional space)
*/
int approach2(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i <= n; i++)
    {
        if (i >= arr.size() || arr[i] != i)
            return i;
    }
    return -1;
}

/*
Approach 3: Hashing
- Time Complexity: O(n) + O(n+1) = O(2n+1) = O(n)
    One loop to fill hash, one loop to find missing number
- Space Complexity: O(n+1) = O(n)
    Hash table of size n+1
*/
int approach3(vector<int> arr, int n)
{
    vector<int> hash(n + 1, 0);
    for (int num : arr)
        hash[num]++;

    for (int i = 0; i <= n; i++)
    {
        if (hash[i] == 0)
            return i;
    }
    return -1;
}

/*
Approach 4: Sum Formula
- Time Complexity: O(n)
    One loop to sum all elements
- Space Complexity: O(1)
*/
int approach4(vector<int> arr, int n)
{
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;
    for (int num : arr)
        actualSum += num;
    return expectedSum - actualSum;
}

/*
Approach 5: XOR
- Time Complexity: O(n)
    One loop to XOR all values
- Space Complexity: O(1)
*/
int approach5(vector<int> arr, int n)
{
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < n; i++)
    {
        xor1 ^= arr[i]; // XOR of all elements
        xor2 ^= i;      // XOR of indices
    }
    xor2 ^= n;          // include last index (0 to n)
    return xor1 ^ xor2; // missing number
}

int main()
{
    int n;
    cout << "Enter value of n (array will have n elements from 0 to n with one missing): ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the " << n << " elements (0 to " << n << ", with one missing):\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\n--- Results from Different Approaches ---\n";
    cout << "Approach 1 (Brute Force Nested Loop): " << approach1(arr, n) << endl;
    cout << "Approach 2 (Sorting-Based): " << approach2(arr, n) << endl;
    cout << "Approach 3 (Hashing): " << approach3(arr, n) << endl;
    cout << "Approach 4 (Sum Formula): " << approach4(arr, n) << endl;
    cout << "Approach 5 (XOR): " << approach5(arr, n) << endl;

    return 0;
}
