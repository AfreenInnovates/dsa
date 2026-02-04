// so we know the sum of n natural numbers is n(n+1)/2
// sum till n-k numbers would be, (n-k)(n-k+1) / 2
// so sum of k numbers from the end (max sum of k numbers) would be total - sum till n-k terms
// example: 1 2 3 4 5 6 7 8 9 10
// min sum for k= 3, 1+2+3 =6 ((3*(3+1)/2))
// max sum for k=3, 10+9+8=27
// total sum = 55
// sum till n-k (till 10-3 = 7th term) = 7*(7+1) / 2 = 28 
// 28+27 = 55
// so we get 27 by (total)-(sum till n-k)

//we can get the required sum, if it is greater than the minimum sum and lesser than the maximum sum, in the range of n

//example: n=5,k=3,x=3
// numbers: 1 2 3 4 5
// the minimum sum possible would be the k terms from start, which is 1+2+3=6
//and the maximum possible sum would be k terms from end, which is 5+4+3=12
// 3 does not lie between them
//1+2+3 > 3 or any other combination is greater

//example: n=5, k=3,x=10
// min sum=1+2+3= 6
//max sum = 8+9+10 = 27
// 10 lies between them, and we can make a combination of 3 numbers to get 10

// so if the required sum is less than the minimum sum (after taking k numbers), then ofc not possible
// and if the required sum is greater than max sum, also not possible
// so x must be between the min and max sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--) {
        long long n,k,x;

        cin>>n>>k>>x;

        long long minSum = (k*(k+1))/2;
        long long maxSum = (n*(n+1)/2) - ((n-k)*(n-k+1)/2);

        if (x >= minSum && x <= maxSum) cout << "yes"<<endl;
        else cout << "no"<<endl;
    }
    return 0;
}