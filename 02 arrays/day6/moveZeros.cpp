#include <bits/stdc++.h>
using namespace std;

void approach1(vector<int> &arr, int n)
{
    vector<int> temp;
    for (auto i : arr)
    {
        if (i != 0)
        {
            temp.push_back(i);
        }
    }

    int temp_len = temp.size();

    for (int i = 0; i < temp_len; i++)
    {
        arr[i] = temp[i];
    }

    for (int i = temp_len; i < n; i++)
    {
        arr[i] = 0;
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

    approach1(arr, n);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
