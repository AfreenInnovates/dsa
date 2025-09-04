#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfPairs(vector<vector<int>> &points)
    {
        int ans = 0;
        sort(points.begin(), points.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
             });

        for (int i = 0; i < points.size() - 1; i++)
        {
            const auto &pointA = points[i];
            int xMin = pointA[0] - 1;
            int xMax = INT_MAX;
            int yMin = INT_MIN;
            int yMax = pointA[1] + 1;

            for (int j = i + 1; j < points.size(); j++)
            {
                const auto &pointB = points[j];
                if (pointB[0] > xMin && pointB[0] < xMax && pointB[1] > yMin &&
                    pointB[1] < yMax)
                {
                    ans++;
                    xMin = pointB[0];
                    yMin = pointB[1];
                }
            }
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> points[i][0] >> points[i][1];
    }

    Solution sol;
    cout << sol.numberOfPairs(points) << "\n";

    return 0;
}