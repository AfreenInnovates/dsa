#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// time complexity:
// O(d) + O(n-d) + O(d) = O(n+d) ≈ O(n)
// space complexity:
// O(d) : temporary array of size d
// multiple of 'n' rotations gives us same array
void approach1(int arr[], int n, int d)
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
// O(d) + O(n-d) + O(n) = O(2n) ≈ O(n)
// space complexity:
// O(1) : in-place reversal, no extra array
void approach2(int arr[], int n, int d)
{
    d = d % n;
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
}

// Helper to print array
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
    cout << "Enter elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int d;
    cout << "Enter rotating number: ";
    cin >> d;

    // Copy original array for second test
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
    }

    // Measure Approach 1 time
    auto start1 = high_resolution_clock::now();
    approach1(arr1, n, d);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end1 - start1);

    cout << "Approach 1 result: ";
    printArray(arr1, n);
    cout << "Approach 1 execution time: " << duration1.count() << " ns\n";

    // Measure Approach 2 time
    auto start2 = high_resolution_clock::now();
    approach2(arr2, n, d);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(end2 - start2);

    cout << "Approach 2 result: ";
    printArray(arr2, n);
    cout << "Approach 2 execution time: " << duration2.count() << " ns\n";

    return 0;
}
