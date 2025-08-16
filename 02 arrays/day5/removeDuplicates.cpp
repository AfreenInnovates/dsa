#include <bits/stdc++.h>
using namespace std;

// time: O(n^2) nested loops
// space: O(n) for storing result
void removeDuplicatesBrute(vector<int> arr)
{
    vector<int> result;
    // 1 1 2 2 3 3
    for (int i = 0; i < arr.size(); i++)
    {
        bool found = false;
        for (int j = 0; j < result.size(); j++)
        {
            if (result[j] == arr[i])
            {
                found = true;
                break;
            }
        }

        if (!found)
            result.push_back(arr[i]);
    }

    cout << "After removing duplicates (Brute): ";
    for (int num : result)
        cout << num << " ";
    cout << "\n";
}

void removeDuplicatesBetter(vector<int> arr)
{
    set<int> s(arr.begin(), arr.end());

    cout << "After removing duplicates (Better): ";
    for (int num : s)
        cout << num << " ";
    cout << "\n";
}

void removeDuplicatesOptimal(vector<int> arr)
{
    sort(arr.begin(), arr.end()); // O(n log n)
    int j = 0;                    // pointer for unique position

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }

    cout << "After removing duplicates (Optimal): ";
    for (int i = 0; i <= j; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    vector<int> arr = {0, 0, 1, 2, 3};

    removeDuplicatesBrute(arr);
    removeDuplicatesBetter(arr);
    removeDuplicatesOptimal(arr);

    return 0;
}
