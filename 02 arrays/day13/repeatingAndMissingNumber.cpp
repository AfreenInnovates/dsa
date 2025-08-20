#include <bits/stdc++.h>
using namespace std;

// time : O(2N)
// space : O(N) using hash array
vector<int> better(vector<int> arr)
{
    int n = arr.size();
    vector<int> hash(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    int repeatingNum = -1, missingNum = -1;
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 2)
        {
            repeatingNum = i;
        }
        else if (hash[i] == 0)
        {
            missingNum = i;
        }
        if (repeatingNum != -1 && missingNum != -1)
            break;
    }

    return {repeatingNum, missingNum};
}

// time : O(N)
// space : O(1)
vector<int> optimal1(vector<int> arr)
{
    int n = arr.size();
    long long S1 = 0, S2 = 0;
    long long S1n = (n * (n + 1)) / 2;
    long long S2n = (n * (n + 1) * (2 * n + 1)) / 6;

    for (auto num : arr)
    {
        S1 += num;
        S2 += (num * num);
    }

    long long val1 = S1n - S1;
    long long val2 = S2n - S2;

    val2 = val2 / val1;

    long long x = (val2 + val1) / 2;
    long long y = val2 - x;

    return {int(y), int(x)};
}

int main()
{
    vector<int> arr = {3, 1, 2, 5, 3};

    auto result1 = better(arr);
    cout << "[Better] Repeating Number: " << result1[0]
         << ", Missing Number: " << result1[1] << endl;

    auto result2 = optimal1(arr);
    cout << "[Optimal] Repeating Number: " << result2[0]
         << ", Missing Number: " << result2[1] << endl;

    return 0;
}