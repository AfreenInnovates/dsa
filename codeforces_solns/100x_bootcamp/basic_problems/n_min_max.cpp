#include<bits/stdc++.h>
using namespace std;

int main() {
    long long a,b;
    cin >> a >> b;

    if (a>b) {
        cout << "Min = " << b<<endl;
        cout << "Max = " << a<<endl;
    } else {
        cout << "Min = " << a<<endl;
        cout << "Max = " << b<<endl;
    }

    return 0;
}