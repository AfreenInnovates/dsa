#include<bits/stdc++.h>
using namespace std;

bool checkSubstr(string s, string x) {
    if (x.size() < s.size()) return false;

    for (int i = 0; i < x.size(); i++) {
        if (x.substr(i, s.size()) == s) return true;
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, m;
        cin >> n >> m;
        string x;
        string s;
        cin >> x;
        cin >> s;

        string singlex=x;
        string twicex=singlex+x;
        string thricex = twicex+twicex;
        string four_x = thricex + thricex;
        string five_x = four_x + four_x;
        string six_x = five_x + five_x;

        int ans = -1;

        if (checkSubstr(s, singlex)) ans = 0;
        else if (checkSubstr(s, twicex)) ans = 1;
        else if (checkSubstr(s, thricex)) ans = 2;
        else if (checkSubstr(s, four_x)) ans = 3;
        else if (checkSubstr(s, five_x)) ans = 4;
        else if (checkSubstr(s, six_x)) ans = 5;

        cout << ans << endl;
    }
}