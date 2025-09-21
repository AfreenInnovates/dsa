#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
   Given a non-empty array of digits representing a non-negative integer,
   increment the integer by one and return the resulting array of digits.
   Digits are stored in most significant order, and no leading zeros exist.
*/

// https://leetcode.com/problems/plus-one/description/

// approach 1
// Time Complexity: O(n) -> iterate from the last digit to the first
// Space Complexity: O(1) -> modifies input in place (except one insert in worst case)
vector<int> plusOne(vector<int> &digits)
{

    for (int i = digits.size() - 1; i >= 0; i--)
    {
        if (digits[i] < 9)
        {
            digits[i] += 1;
            return digits;
        }

        digits[i] = 0; // if the digit is greater than 9, we'll just make it zero and then add one to the next number
    }

    // when all digits are 9, the vector elements are made all 0, and then 1 is inserted in the beginning
    digits.insert(digits.begin(), 1);
    return digits;
}

// approach 2
// Time Complexity: O(n) -> traverse digits once, handling carry
// Space Complexity: O(1) -> modifies input in place
class Solution2
{
public:
    vector<int> plusOne(vector<int> &v)
    {
        int n = v.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
                v[i]++;
            if (v[i] == 10)
            {
                v[i] = 0;
                if (i != 0)
                {
                    v[i - 1]++;
                }
                else
                {
                    v.push_back(0);
                    v[i] = 1;
                }
            }
        }
        return v;
    }
};

// approach 3
// Time Complexity: O(n) -> convert to string, simulate addition, then convert back
// Space Complexity: O(n) -> uses extra string and result vector
class Solution3
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        // convert vector<int> to string
        string num = "";
        for (int d : digits)
        {
            num.push_back(d + '0'); // convert int -> char
        }

        // add 1 manually to the string number
        int carry = 1; // we want to add 1
        for (int i = num.size() - 1; i >= 0 && carry; i--)
        {
            int val = (num[i] - '0') + carry;
            num[i] = (val % 10) + '0';
            carry = val / 10;
        }

        if (carry)
        {
            num.insert(num.begin(), '1'); // insert '1' at front
        }

        // convert string back to vector<int>
        vector<int> result;
        for (char c : num)
        {
            result.push_back(c - '0');
        }
        return result;
    }
};

int main()
{
    vector<int> digits = {9, 9, 9};

    cout << "Input digits: ";
    for (int d : digits)
        cout << d;
    cout << endl;

    vector<int> res1 = plusOne(digits);
    cout << "Approach 1 Result: ";
    for (int d : res1)
        cout << d;
    cout << endl;

    Solution2 s2;
    vector<int> res2 = s2.plusOne(digits);
    cout << "Approach 2 Result: ";
    for (int d : res2)
        cout << d;
    cout << endl;

    Solution3 s3;
    vector<int> res3 = s3.plusOne(digits);
    cout << "Approach 3 Result: ";
    for (int d : res3)
        cout << d;
    cout << endl;

    return 0;
}
