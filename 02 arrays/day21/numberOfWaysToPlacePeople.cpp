#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity:
- Outer two loops: O(n^2) for choosing points A and B.
- Inner loop over k: O(n) in worst case.
- Overall worst-case: O(n^3), where n = number of points.

Space Complexity:
- O(1)
*/

int numberOfPairs(vector<vector<int>> &points)
{
    int ans = 0;
    int n = points.size();

    for (int i = 0; i < n; i++)
    {
        auto &A = points[i];
        for (int j = 0; j < n; j++)
        {
            auto &B = points[j];

            // Skip if same point or if B does not form valid rectangle with A
            if (i == j || !(A[0] <= B[0] && A[1] >= B[1]))
            {
                continue;
            }

            if (n == 2)
            {
                ans++;
                continue;
            }

            bool empty_rec = false;
            for (int k = 0; k < n; k++)
            {
                if (k == i || k == j)
                    continue;

                auto &C = points[k];
                bool isXContained = C[0] >= A[0] && C[0] <= B[0];
                bool isYContained = C[1] <= A[1] && C[1] >= B[1];

                if (isXContained && isYContained)
                {
                    empty_rec = true;
                    break;
                }
            }

            if (!empty_rec)
            {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> points = {{1, 3}, {2, 2}, {3, 1}};

    int result = numberOfPairs(points);
    cout << "Number of valid pairs: " << result << endl;

    return 0;
}
