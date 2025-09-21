/*
Problem: Earliest Completion Time
https://leetcode.com/problems/earliest-time-to-finish-one-task/
-----------------------------------
You are given a list of tasks, where each task is represented as a vector<int> of size 2.
- task[0] = start time
- task[1] = duration

You need to find the **earliest possible completion time** among all tasks.
Completion time of a task = task[0] + task[1]
Return the minimum completion time.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/*
Approach 1: Using auxiliary vector
-----------------------------------
- Compute completion time for each task and store in a vector
- Then take the minimum using min_element
- Time Complexity: O(N)
- Space Complexity: O(N) (for the extra vector)
*/
int earliestTimeAux(vector<vector<int>> &tasks)
{
    vector<int> allTimes;

    for (auto &task : tasks)
    {
        allTimes.push_back(task[0] + task[1]);
    }

    return *min_element(allTimes.begin(), allTimes.end());
}

/*
Approach 2: Optimized (running minimum)
----------------------------------------
- Maintain a variable to store current minimum while iterating
- No extra vector needed
- Time Complexity: O(N)
- Space Complexity: O(1)
*/
int earliestTimeOptimized(vector<vector<int>> &tasks)
{
    int mini = INT_MAX;

    for (auto &task : tasks)
    {
        mini = min(task[0] + task[1], mini);
    }

    return mini;
}

int main()
{
    vector<vector<int>> tasks = {{1, 3}, {2, 1}, {4, 2}, {0, 5}};

    cout << "Earliest time (Aux vector): " << earliestTimeAux(tasks) << endl;
    cout << "Earliest time (Optimized):  " << earliestTimeOptimized(tasks) << endl;

    return 0;
}
