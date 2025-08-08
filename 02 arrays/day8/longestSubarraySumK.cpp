#include <bits/stdc++.h>
using namespace std;

// time: close to O(n^3)
int bruteApproach(vector<int> arr, int n, int num)
{
    int maxLength = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }

            if (sum == num)
            {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}

int main()
{
    int n, num;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> num;

    int result = bruteApproach(arr, n, num);

    cout << "Maximum subarray length with sum = " << num << " is: " << result << endl;

    return 0;
}