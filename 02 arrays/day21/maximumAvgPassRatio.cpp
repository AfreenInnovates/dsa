#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // --------------------------------------------------------
    // gain_function(pass, total):
    // Time Complexity: O(1) → just a few arithmetic operations
    // Space Complexity: O(1) → no extra memory used
    double gain_function(int pass, int total)
    {
        double oldRatio = (double)pass / total;
        double newRatio = (double)(pass + 1) / (total + 1);

        return newRatio - oldRatio;
    }
    // --------------------------------------------------------
    // maxAverageRatio(classes, extraStudents):
    //
    // n = number of classes
    // k = number of extra students
    //
    // Time Complexity:
    //   O(n log n) to build the heap initially
    //   O(k log n) because each extra student insertion/removal
    //              from heap takes log n
    //   Total → O((n + k) log n)
    //
    // Space Complexity:
    //   O(n) → we store all classes in the heap
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {

        // priority queue
        priority_queue<pair<double, pair<int, int>>> pq;

        for (auto &c : classes)
        {
            pq.push({gain_function(c[0], c[1]), {c[0], c[1]}});
            // heap element looks like : {gain, {number_passed, total_students}}
        }

        while (extraStudents--)
        {
            auto best = pq.top(); // --> gets element with largest gain
            pq.pop();             // removing it

            int pass = best.second.first;   // from {gain, {pass, total}}, we take the second's first, that is the pass number
            int total = best.second.second; // same here, but second's second to get total number
            pass++;
            total++;

            pq.push({gain_function(pass, total), {pass, total}});
        }

        double result = 0.0;

        while (!pq.empty())
        {
            auto cls = pq.top().second; // get the pass and total number from top of queue
            pq.pop();                   // then remove it

            result += (double)cls.first / cls.second;
        }

        return result / classes.size();
        // result contains the pass ratios of each class
        // to get average pass ratio of all class, we divide the result by total number of classes
    }
};

// --------------------------------------------------------
// bruteForceApproach(classes, extraStudents):
//
// n = number of classes
// k = number of extra students
//
// Time Complexity:
//   Each student assignment requires checking all classes (O(n))
//   and we do this for k students → O(n * k)
// Space Complexity:
//   O(n) → for storing passRatios and updatedRatios
// --------------------------------------------------------
double bruteForceApproach(vector<vector<int>> &classes, int extraStudents)
{
    vector<double> passRatios;

    for (int i = 0; i < classes.size(); i++)
    {
        double initialRatio = classes[i][0] / (double)classes[i][1];
        passRatios.push_back(initialRatio);
    }

    while (extraStudents--)
    {
        vector<double> updatedRatios;

        for (int i = 0; i < classes.size(); i++)
        {
            double newRatio =
                (classes[i][0] + 1) / double(classes[i][1] + 1);
            updatedRatios.push_back(newRatio);
        }

        int bestClass = 0;
        double maximumGain = 0;

        for (int i = 0; i < updatedRatios.size(); i++)
        {
            double gain = updatedRatios[i] - passRatios[i];
            if (gain > maximumGain)
            {
                bestClass = i;
                maximumGain = gain;
            }
        }

        passRatios[bestClass] = updatedRatios[bestClass];
        classes[bestClass][0]++;
        classes[bestClass][1]++;
    }

    double totalPassRatio = 0;
    for (double passRatio : passRatios)
    {
        totalPassRatio += passRatio;
    }

    return totalPassRatio / classes.size();
}

int main()
{
    vector<vector<int>> classes = {{2, 4}, {3, 9}, {4, 5}, {2, 10}};
    int extraStudents = 4;

    // Make a copy for brute force, because it modifies the input
    vector<vector<int>> classesForBrute = classes;
    double bruteResult = bruteForceApproach(classesForBrute, extraStudents);
    cout << fixed << setprecision(6);
    cout << "Brute Force Result = " << bruteResult << endl;

    // Make a copy for optimized, because it also modifies the input
    vector<vector<int>> classesForOptimized = classes;
    Solution sol;
    double optimizedResult = sol.maxAverageRatio(classesForOptimized, extraStudents);
    cout << "Optimized Result   = " << optimizedResult << endl;

    return 0;
}
