#include <bits/stdc++.h>
using namespace std;

// goes from n, n-1, n-2, n-3, ..... 3, 2, 1
// so the time complexity is n: O(n)
int computeFactorial(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }

    else
    {
        return n * computeFactorial(n - 1);
    }
}

// runs numbers of times k divides n!
// close to n times in worst case
// O(n)
int maxKPower(int k, int n)
{
    int factOfn = computeFactorial(n);

    int power = 0;

    while (factOfn % k == 0)
    {
        factOfn = factOfn / k;
        power++;
    }

    return power;
}

int main()
{
    int n, k;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter k: ";
    cin >> k;

    cout << "Max power of k: " << maxKPower(k, n);

    return 0;
}

// total time complexity:
// O(n+n) = O(2n) = O(n)
// auxillary space: O(1)