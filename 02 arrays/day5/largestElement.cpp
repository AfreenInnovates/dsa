// brute force:
// sort elements and then get the arr[n-1]th value
// time complexity: O(n log(n))
// space complexity: O(1)

// best:
// assign largest as arr[0]
// loop through all elements
// compare arr[0] with every element, and re assign the largest

#include <bits/stdc++.h>
using namespace std;

int largest(vector<int> &arr)
{

    int large = arr.at(0);
    for (auto i : arr)
    {
        if (i > large)
        {
            large = i;
        }
    }

    return large;
}

int main()
{
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    cout << "Largest element: " << largest(arr) << endl;
}
