#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int size;
        cin >> size;

        vector<int> arr(size);
        bool odd = false, even = false;

        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
                even = true;
            else
                odd = true;
        }

        if (odd && even) // both parity types exist
            sort(arr.begin(), arr.end());

        for (int x : arr)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}