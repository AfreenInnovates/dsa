#include <bits/stdc++.h>
using namespace std;

// method 1
void revArray(int arr[], int newArr[], int i, int n)
{
    if (i < 0)
        return;

    newArr[n - i - 1] = arr[i];
    revArray(arr, newArr, i - 1, n);
}

// method 2
void reverseArray(int arr[], int start, int end)
{
    if (start < end)
    {
        swap(arr[start], arr[end]);
        reverseArray(arr, start + 1, end - 1);
    }
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter array lenght: ";
    cin >> n;

    int arr[n], newArr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter number: ";
        cin >> arr[i];
    }

    // method 1 codes
    // revArray(arr, newArr, n - 1, n);
    // printArr(newArr, n);

    // method 2 codes
    reverseArray(arr, 0, n - 1);
    printArr(arr, n);
}
