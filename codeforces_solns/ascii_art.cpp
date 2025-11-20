#include <bits/stdc++.h>
using namespace std;

int main()
{

    int g, c, l;

    cin >> g >> c >> l;

    int max_score = max({g, c, l});
    int min_score = min({g, c, l});

    if (max_score - min_score >= 10)
        cout << "check again\n";
    else
    {
        vector<int> v = {g, c, l};
        sort(v.begin(), v.end());
        cout << "final " << v[1] << endl;
    }

    return 0;
}
