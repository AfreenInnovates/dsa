// The product of all elements becomes 0 if and only if at least one element is 0
// So we only need to make any single array element equal to 0
// In one operation, we can increase or decrease an element by 1
// To convert Ai to 0, it takes exactly |Ai| operations.
// Therefore, to minimize operations, we should choose the element
// with the smallest absolute value and reduce it to 0.
// If the array already contains a 0, no operation is needed.
// Otherwise, the answer is min(|Ai|) over all elements.

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long x, mini=LLONG_MAX;
    bool has0=false;

    for (int i=0;i<n;i++) {
        cin>>x;

        if (x==0) has0=true;

        mini = min(mini, llabs(x));
    }

    if (has0) cout << 0 << endl; // if already has 0, no need to do anything, product is already 0
    else cout << mini << endl; // else we reduce the element that can be turned into 0 in least number of operations

    return 0;
}