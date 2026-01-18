#include<bits/stdc++.h>
using namespace std;

int main() {

    int a, b;
    cin >> a >> b;

    // get the last digits of a and b
    int d1 = a%10;
    int d2 = b%10;

    cout << d1+d2<<endl;

    return 0;
}