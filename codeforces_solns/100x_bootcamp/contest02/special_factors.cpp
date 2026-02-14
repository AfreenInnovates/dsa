// Given an integer N
// , print all special factors∗
//  of N
//  in increasing order.

// A factor is called special if its last digit is 2
//  or 7
//  (i.e., dmod10∈{2,7}
// ).

// ∗
// A positive integer d
//  is a factor of N
//  if Nmodd=0
// .

#include<bits/stdc++.h>
using namespace std;

int main() {
     int n;
    cin >> n;

    int count = 0;
    for(int i = 1; i<= n; i++)
    {
        if(n % i == 0)
        {
            int lastDigit = i % 10;
            
            if(lastDigit == 2 or lastDigit == 7)
            {
                cout << i << " ";
                count++;
            }
        }
    }

    if(count == 0)
    {
        cout << -1;
    }
}