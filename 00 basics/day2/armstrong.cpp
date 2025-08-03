#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, num, count = 0, sum = 0;
    cout << "Enter a number: ";
    cin >> n;

    num = n;

    // Count number of digits
    while (num > 0)
    {
        count++;
        num = num / 10;
    }

    cout << "Number of digits: " << count << endl;

    num = n;
    while (num > 0)
    {
        int last_dig = num % 10;
        sum += round(pow(last_dig, count));
        num = num / 10;
    }

    cout << "Calculated sum: " << sum << endl;

    if (sum == n)
    {
        cout << n << " is an Armstrong number." << endl;
    }
    else
    {
        cout << n << " is NOT an Armstrong number." << endl;
    }

    return 0;
}
