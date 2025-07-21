#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << endl;

    int num = n;
    int count = 0;

    while (num != 0)
    {
        int last_dig = num % 10;
        count++;
        num = num / 10;
    }

    cout << "Number of digits in " << n << " is: " << count;
}