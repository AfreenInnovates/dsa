#include <iostream>
using namespace std;

int numberOfDivisors(int num)
{
    int c = 0;

    // iterate and check if factor or not
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            c += 1;
        }
    }
    return c;
}

// Function to count numbers having
// exactly 9 divisors
int countNumbers(int n)
{
    int c = 0;

    // check for all numbers <=n
    for (int i = 1; i <= n; i++)
    {

        // check if exactly 9 factors or not
        if (numberOfDivisors(i) == 9)
            c += 1;
    }
    return c;
}

int main()
{
    int n = 100;

    cout << countNumbers(n);

    return 0;
}

// Time Complexity: O(n^2)
// Auxiliary Space: O(1)