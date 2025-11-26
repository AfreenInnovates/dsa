#include <bits/stdc++.h>
using namespace std;

int findMissingNum(int n, vector<int> arr)
{
    vector<int> hash(n + 1, 0);

    for (size_t i = 0; i < arr.size(); i++)
    {
        hash[arr[i]]++;
    }

    for (size_t i = 1; i < hash.size(); i++)
    {
        if (hash[i] == 0)
        {
            return (int)i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }

    cout << findMissingNum(n, arr);
    return 0;
}
