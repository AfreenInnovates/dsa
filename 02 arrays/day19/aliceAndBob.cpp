#include <iostream>
using namespace std;

class Solution
{
public:
    long long flowerGame(int n, int m)
    {
        long long x = 0, y = 0;
        long long eveny = (m / 2);
        long long oddy = (m + 1) / 2;
        long long wins = 0;
        for (x = 1; x <= n; x++)
        {
            if (x % 2 == 0)
            {
                wins += oddy;
            }
            else
            {
                wins += eveny;
            }
        }

        return wins;
    }
};

int main()
{
    Solution sol;

    int n, m;
    cout << "Enter n and m: ";
    cin >> n >> m;

    long long result = sol.flowerGame(n, m);
    cout << "Number of wins: " << result << endl;

    return 0;
}
