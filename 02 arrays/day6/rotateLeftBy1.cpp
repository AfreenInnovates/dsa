#include <bits/stdc++.h>
using namespace std;

// for n = 5
// i runs from
// i = 1, 2, 3, 4
// O(n-1) = O(n)
// space complexity: O(1) (extra space used?)
// space to solve the problem: O(n)
void approach1(int arr[], int n)
{
    int temp = arr[0];

    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }

    arr[n - 1] = temp;
}

int main()
{
    int n;
    cout << "Enter length of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter num: ";
        cin >> arr[i];
    }

    approach1(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}