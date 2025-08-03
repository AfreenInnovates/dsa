#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << endl;

    int num = abs(n);
    int rev_num = 0;

    while (num > 0)
    {
        int last_dig = num % 10;
        cout << last_dig << endl;
        rev_num = (rev_num * 10) + last_dig;
        cout << rev_num << endl;
        num = num / 10;
        cout << num << endl;
    }

    if (n < 0)
    {
        rev_num = (-rev_num);
    }
    cout << "Reverse of number " << n << " is: " << rev_num;
}