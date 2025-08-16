#include <bits/stdc++.h>
using namespace std;

vector<int> altNumbers(vector<int> nums)
{
    int n = nums.size();

    vector<int> pos;
    vector<int> neg;

    for (auto num : nums)
    {
        if (num < 0)
            neg.push_back(num);
        else
            pos.push_back(num);
    }

    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            nums[i * 2] = pos[i];
            nums[i * 2 + 1] = neg[i];
        }

        int nextIndex = 2 * neg.size();
        for (int i = neg.size(); i < pos.size(); i++)
        {
            nums[nextIndex] = pos[i];
            nextIndex++;
        }
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            nums[i * 2] = pos[i];
            nums[i * 2 + 1] = neg[i];
        }

        int nextIndex = 2 * pos.size();
        for (int i = pos.size(); i < neg.size(); i++)
        {
            nums[nextIndex] = neg[i];
            nextIndex++;
        }
    }

    return nums;
}

int main()
{
    vector<int> arr = {3, 1, -2, -5, 2, -4, 6};

    cout << "Original array:\n";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";

    vector<int> result = altNumbers(arr);

    cout << "\nRearranged array (alternating):\n";
    for (int x : result)
        cout << x << " ";
    cout << "\n";

    return 0;
}
