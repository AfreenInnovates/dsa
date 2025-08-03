#include <bits/stdc++.h>
using namespace std;

int largestBruteForce(vector<int> &arr)
{
    sort(arr.begin(), arr.end()); // O(n log n)
    return arr.back();            // last element is largest
}

int main()
{
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    cout << "Largest element: " << largestBruteForce(arr) << endl;
}
