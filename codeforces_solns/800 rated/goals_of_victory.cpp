// let's take an example of one team match
// team 1 vs team 2:
// 1 - 2     (1 goal scored by team 1, and 2 goals by team 2)
// team 2 vs team 1 would be:
// 2 - 1     (2 goals by team 2 and 1 goal by team 1)
// the efficiency for team 1 would be : goals scored by team 1 - goals scored by its opponent team 2 = (1+1) - (2+2) = 2 - 4 = -2
// the efficiency for team 2 would be : goals scored by team 2 - goals scored by its opponent team 1 = (2+2) - (1+1) = 4 - 2 = 2
// so if there were two teams, like team 1 and team 2 like above case
// the efficiency for team 1 and team 2 is -2 and 2 respectively
// the total sum of efficiency is 2+(-2) = 0

// so this would be the same for any number of teams

// let's take example of first test case from here : https://codeforces.com/problemset/problem/1877/A
// team 1 vs team 2 : 1 - 2
// team 1 vs team 3 : 3 - 0
// team 1 vs team 4 : 3 - 2
// team 2 vs team 3 : 1 - 4
// team 2 vs team 4 : 1 - 3
// team 3 vs team 4 : 5 - 0

// i though of generating cases of number of goals

// but if we calculate efficiencies of each team:
// team 1 total goals : 1, 3, 3
// goals scored by opponents of team 1 : 2, 0, 2
// so efficiency of team 1 : (1+3+3) - (2+0+2) = 3

// team 2 goals: 1, 1, 2
// goals scored by opponents of team 2: 1, 4, 3
// efficiency of team 2 : (1+1+2) - (1+4+3) = -4

// team 3 goals: 0, 4, 5
// goals by opponents of team 3: 3, 1, 0
// efficiency of team 3: (0+4+5) - (3+1+0) = 5

// team 4 goals: 2, 3, 0
// goals by opponents of team 4: 3, 1, 5
// efficiency of team 4: (2+3+0) - (3+1+5) = -4

// sum of all efficiencies = 3+(-4)+5+(-4) = -1+1 = 0

// sum of given efficiencies would be : 3+(-4)+5 = -1+5 = 4
// not known: -4
// as sum of all given = 0
// a1+a2+a3 + unknown = 0
// unknown = -(a1+a2+a3)

#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long sum = 0;
        for (int i = 0; i < n - 1; i++) {
            long long x;
            cin >> x;
            sum += x;
        }
        cout << -sum << '\n';
    }
}
