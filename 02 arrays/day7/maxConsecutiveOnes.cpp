#include <bits/stdc++.h>
using namespace std;

// time: O(n)
// space: O(1)
int countMaxConsOnes(vector<int> arr)
{
    int max1 = 0, count = 0;

    for (auto num : arr)
    {
        if (num == 1)
        {
            count += 1;
            max1 = max(count, max1);
        }
        else
        {
            count = 0;
        }
    }

    return max1;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements (only 0s and 1s):\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = countMaxConsOnes(arr);
    cout << "Maximum number of consecutive 1s: " << result << endl;

    return 0;
}
