#include <bits/stdc++.h>
using namespace std;

//----------------------------------------------------
// Brute Force: Check each element and count frequency
// Time: O(n^2)
// Space: O(1) extra space
//----------------------------------------------------
vector<int> brute(vector<int> arr, int n)
{
    vector<int> ls;
    for (int i = 0; i < n; i++)
    {
        if (find(ls.begin(), ls.end(), arr[i]) == ls.end()) // avoid duplicates
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == arr[i])
                {
                    count++;
                }
            }
            if (count > n / 3)
            {
                ls.push_back(arr[i]);
            }
        }
    }
    return ls;
}

//----------------------------------------------------
// Better Approach: Hashing
// Time: O(n)
// Space: O(n)
//----------------------------------------------------
vector<int> better(vector<int> arr, int n)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    vector<int> res;
    for (auto &it : freq)
    {
        if (it.second > n / 3)
        {
            res.push_back(it.first);
        }
    }
    return res;
}

//----------------------------------------------------
// Optimal: Boyer–Moore Voting Algorithm for n/3
// Time: O(n)
// Space: O(1)
//----------------------------------------------------
vector<int> optimal(vector<int> arr, int n)
{
    int count1 = 0, count2 = 0;
    int candidate1 = INT_MIN, candidate2 = INT_MIN;

    // 1st pass: Find potential candidates
    for (int num : arr)
    {
        if (num == candidate1)
            count1++;
        else if (num == candidate2)
            count2++;
        else if (count1 == 0)
        {
            candidate1 = num;
            count1 = 1;
        }
        else if (count2 == 0)
        {
            candidate2 = num;
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    // 2nd pass: Verify candidates
    count1 = count2 = 0;
    for (int num : arr)
    {
        if (num == candidate1)
            count1++;
        else if (num == candidate2)
            count2++;
    }

    vector<int> res;
    if (count1 > n / 3)
        res.push_back(candidate1);
    if (count2 > n / 3)
        res.push_back(candidate2);

    return res;
}

//----------------------------------------------------
// MAIN FUNCTION
//----------------------------------------------------
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans1 = brute(arr, n);
    vector<int> ans2 = better(arr, n);
    vector<int> ans3 = optimal(arr, n);

    cout << "\nBrute Force Result: ";
    for (int x : ans1)
        cout << x << " ";
    cout << "\nBetter (Hashing) Result: ";
    for (int x : ans2)
        cout << x << " ";
    cout << "\nOptimal (Boyer-Moore) Result: ";
    for (int x : ans3)
        cout << x << " ";
    cout << endl;

    return 0;
}
