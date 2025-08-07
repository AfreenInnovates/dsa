#include <bits/stdc++.h>
using namespace std;

void approach1(vector<int> &arr, int n)
{
    vector<int> temp;
    // O (N)
    for (auto i : arr)
    {
        if (i != 0)
        {
            temp.push_back(i);
        }
    }

    int temp_len = temp.size();

    // O(x)
    for (int i = 0; i < temp_len; i++)
    {
        arr[i] = temp[i];
    }

    // O(n-x)
    for (int i = temp_len; i < n; i++)
    {
        arr[i] = 0;
    }
}

void approach2(vector<int> &arr, int n)
{
    int j = -1;
    // O(x)
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
        return;

    // from j+1 till n; so O(n-x)
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr;
    arr.reserve(n);

    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "Enter number: ";
        cin >> val;
        arr.push_back(val);
    }

    vector<int> arr2 = arr;

    // Approach 1
    auto start1 = chrono::high_resolution_clock::now();
    approach1(arr, n);
    auto end1 = chrono::high_resolution_clock::now();

    cout << "Approach 1 result: ";
    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    auto duration1 = chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
    cout << "Approach 1 time: " << duration1 << " ns" << endl;

    // Approach 2
    auto start2 = chrono::high_resolution_clock::now();
    approach2(arr2, n);
    auto end2 = chrono::high_resolution_clock::now();

    cout << "Approach 2 result: ";
    for (auto i : arr2)
        cout << i << " ";
    cout << endl;

    auto duration2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
    cout << "Approach 2 time: " << duration2 << " ns" << endl;

    return 0;
}
