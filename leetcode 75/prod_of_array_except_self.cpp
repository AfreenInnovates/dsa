// brute force
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> newArr;

        int i = 0, j = 0, n = nums.size();

        for (i = 0; i < n; i++)
        {
            int prod = 1;
            for (j = 0; j < n; j++)
            {
                if (i != j)
                {
                    prod = prod * nums[j];
                }
            }

            newArr.push_back(prod);
        }

        return newArr;
    }
};

//