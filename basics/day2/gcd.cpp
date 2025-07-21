#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num1, num2;
    cout << "Enter num 1: ";
    cin >> num1;
    cout << endl;
    cout << "Enter num2: ";
    cin >> num2;
    cout << endl;

    while (num1 > 0 && num2 > 0)
    {
        if (num1 > num2)
            num1 = num1 % num2;
        else
            num2 = num2 % num1;
    }

    if (num1 == 0)
        cout << "GCD: " << num2;
    else
        cout << "GCD: " << num1;
}