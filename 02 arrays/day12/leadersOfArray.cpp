#include <bits/stdc++.h>
using namespace std;

// time: O(n^2)
// space: O(n) -- if we use an array to return the answer (not for solving the problem)
void approach1(vector<int> arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        bool leader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                leader = false;
                break;
            }
        }

        if (leader == true)
        {
            cout << arr[i] << " ";
        }
    }
}

// Time: O(n)
// Space: O(n) -- if we store leaders, O(1) if we just print directly
void approach2(vector<int> arr)
{
    int n = arr.size();
    vector<int> leaders;

    int maxFromRight = arr[n - 1];
    leaders.push_back(maxFromRight); // rightmost element is always a leader

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= maxFromRight)
        {
            leaders.push_back(arr[i]);
            maxFromRight = arr[i];
        }
    }

    // reverse to maintain the original order
    reverse(leaders.begin(), leaders.end());

    for (int x : leaders)
        cout << x << " ";
}

int main()
{
    vector<int> arr = {16, 17, 4, 3, 5, 2};

    cout << "Approach 1 (Brute Force): ";
    approach1(arr);
    cout << "\n";

    cout << "Approach 2 (Optimal): ";
    approach2(arr);
    cout << "\n";

    return 0;
}