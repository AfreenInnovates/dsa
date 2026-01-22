// https://codeforces.com/problemset/problem/1834/A
// array : [a1, a2, ... , an]
// what i think of first:
// good array:
    // a1 + a2 +. .. . an >= 1
        // which would mean, number of 1s >= number of -1s
    // a1*a2*... an = 1
        // which would mean, we must have even number of -1s
// so if we have odd number of -1s 
    // example : -1, -1, 1, 1, -1
        // product = -1
        // sum = -1
        // on changing one of the -1s with 1, it'll become -1, -1, 1, 1, 1
            // now product = 1
            // sum = 1
    // we can change one -1 to 1 to make the array good
    // example (odd number of -1s, and all -1): -1, -1, -1
        // product = -1
        // sum = -3
        // if all are -1s, we need that many number of operatons => change to 1s and then it'll be good array
// if we have even number of -1s
    // example: -1, -1, 1, 1
    // product = 1
    // sum = 0
    // no operations required here
    // example: (even number of -1s, and all -1): -1, -1
        // product = 1
        // sum = -2
        // here also, we need that many number of operations

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >>t;

    while (t--) {
        int n;
        cin>>n;

        int positives=0, negs=0,sum=0,prod=1;

        for (int i=0;i<n;i++) {
            int x;
            cin>>x;

            if (x==1) positives++;
            else negs++;

            sum += x;
            prod *= x;
        }

        int operations=0;
        
        while (positives < negs || negs % 2 == 1) {
            operations++;
            positives++;
            negs--;
        }


        cout << operations<<endl;
    }

    return 0;
}