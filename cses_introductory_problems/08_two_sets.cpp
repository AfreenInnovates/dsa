#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long n;
    cin >> n;

    long long sum = (n * (n + 1)) / 2;

    if (sum % 2 != 0)
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    long long target = sum / 2;
    vector<int> setA, setB;

    for (long long x = n; x >= 1; x--)
    {
        if (x <= target)
        {
            setA.push_back(x);
            target -= x;
        }
        else
        {
            setB.push_back(x);
        }
    }

    cout << setA.size() << "\n";
    for (auto x : setA)
        cout << x << " ";
    cout << "\n";

    cout << setB.size() << "\n";
    for (auto x : setB)
        cout << x << " ";
    cout << "\n";

    return 0;
}