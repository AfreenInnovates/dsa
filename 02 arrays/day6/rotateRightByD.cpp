#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// time complexity:
// O(d) + O(n-d) + O(d) = O(n)
// space complexity:
// O(d) : temporary array of size d
void leftRotateApproach1(int arr[], int n, int d)
{
    d = d % n;
    int temp[d];
    for (int i = 0; i < d; i++)
        temp[i] = arr[i];

    for (int i = d; i < n; i++)
        arr[i - d] = arr[i];

    for (int i = n - d; i < n; i++)
        arr[i] = temp[i - (n - d)];
}

// time complexity:
// O(d) + O(n-d) + O(n) ≈ O(n)
// space complexity:
// O(1) : in-place reversal
void leftRotateApproach2(int arr[], int n, int d)
{
    d = d % n;
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
}

// time complexity:
// O(d) + O(n-d) + O(d) = O(n)
// space complexity:
// O(d)
void rightRotateApproach1(int arr[], int n, int d)
{
    d = d % n;
    int temp[d];

    // Store last d elements
    for (int i = 0; i < d; i++)
        temp[i] = arr[n - d + i];

    // Shift remaining elements right
    for (int i = n - 1; i >= d; i--)
        arr[i] = arr[i - d];

    // Put temp elements at front
    for (int i = 0; i < d; i++)
        arr[i] = temp[i];
}

// time complexity:
// O(n)
// space complexity:
// O(1)
void rightRotateApproach2(int arr[], int n, int d)
{
    d = d % n;
    reverse(arr, arr + n);
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int n;
    cout << "Enter length of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int d;
    cout << "Enter rotating number: ";
    cin >> d;

    int arr1[n], arr2[n], arr3[n], arr4[n];
    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
        arr4[i] = arr[i];
    }

    auto start1 = high_resolution_clock::now();
    leftRotateApproach1(arr1, n, d);
    auto end1 = high_resolution_clock::now();
    cout << "Left Rotation Approach 1: ";
    printArray(arr1, n);
    cout << "Execution time: " << duration_cast<nanoseconds>(end1 - start1).count() << " ns\n";

    auto start2 = high_resolution_clock::now();
    leftRotateApproach2(arr2, n, d);
    auto end2 = high_resolution_clock::now();
    cout << "Left Rotation Approach 2: ";
    printArray(arr2, n);
    cout << "Execution time: " << duration_cast<nanoseconds>(end2 - start2).count() << " ns\n";

    auto start3 = high_resolution_clock::now();
    rightRotateApproach1(arr3, n, d);
    auto end3 = high_resolution_clock::now();
    cout << "Right Rotation Approach 1: ";
    printArray(arr3, n);
    cout << "Execution time: " << duration_cast<nanoseconds>(end3 - start3).count() << " ns\n";

    auto start4 = high_resolution_clock::now();
    rightRotateApproach2(arr4, n, d);
    auto end4 = high_resolution_clock::now();
    cout << "Right Rotation Approach 2: ";
    printArray(arr4, n);
    cout << "Execution time: " << duration_cast<nanoseconds>(end4 - start4).count() << " ns\n";

    return 0;
}
