#include <bits/stdc++.h>
using namespace std;

vector<int> getAlternates1(vector<int> &arr)
{
    vector<int> res;

    for (int i = 0; i < arr.size(); i += 2)
    {
        res.push_back(arr[i]);
    }

    return res;
}

vector<int> getAlternates2(vector<int> &arr, int i)
{
    cout << "Entering recursion with i = " << i << "\n";

    if (i >= arr.size())
    {
        cout << "Base case reached at i = " << i << "\n";
        return {};
    }

    // recursive call
    cout << "Before recursive call: i = " << i << ", arr[i] = " << arr[i] << "\n";
    vector<int> res = getAlternates2(arr, i + 2);
    cout << "After recursive call: i = " << i << ", res = { ";
    for (int x : res)
        cout << x << " ";
    cout << "}\n";

    // insert current element at the beginning
    res.insert(res.begin(), arr[i]);
    cout << "After inserting arr[" << i << "] = " << arr[i] << " → res = { ";
    for (int x : res)
        cout << x << " ";
    cout << "}\n";

    return res;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    vector<int> res1 = getAlternates1(arr);
    vector<int> res2 = getAlternates2(arr, 0);

    cout << "Iterative result: ";
    for (int x : res1)
        cout << x << " ";
    cout << "\n";

    cout << "Recursive result: ";
    for (int x : res2)
        cout << x << " ";
    cout << "\n";

    return 0;
}