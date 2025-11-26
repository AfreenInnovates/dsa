#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    vector<int> arr;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long c = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            while (arr[i] < arr[i - 1])
            {
                arr[i]++;
                c++;
            }
        }
    }

    cout << c;

    return 0;
}