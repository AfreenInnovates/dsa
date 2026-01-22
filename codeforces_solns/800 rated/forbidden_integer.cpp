// to obtain: integer n
// unlimited supply of integer 1 to k, except integer x
// Time limit per test = 2 seconds
// Approx operations per second ≈ 10^8
// So in 2 seconds ≈ 2 × 10^8 operations allowed
// Constraints:
// t ≤ 100
// n ≤ 100
// Worst case operations:
// For each test case, we print at most n numbers
// Total operations ≈ t × n = 100 × 100 = 10^4
// Comparison:
// 10^4 << 2 × 10^8
// Hence:
// O(n) per test case 
// O(t × n) overall 
// n ≤ 100
// O(n^4) not possible
// below that n^3, n^2, n, 1 solutions possible


// if x!=1, and k>=1, then we can get n, by summing 1, n times
// if x==1, and k=1, then no solution possible; as we can't use x, and the limit is to use only till k which is 1, so not possible
// if x==1, and k==2 : we have only 2 to use in this case
    // if n is even, then we can use the number 2 to get n (so n/2 2s required)
    // if n is odd, then not possible
// if x==1, and k>=2 : we can use 2 and 3 in this case:
    // if n is even, yes possible, n/2 2s required
    // if n is odd, n would be greater than k (given in q. : 1 ≤ x ≤ k ≤ n ≤ 100), then n would be 3, 5, 7, 9 ...
        // 3 = one 3 required (3-3 = 0, zero 2s required)
        // 5 = one 3 and one 2 required (5-3=2, one 2 required)
        // 7 = one 3 and two 2 required (7-3=4, two 2s required)
        // 9 = one 3 and three two required (9-3=6, three 2s required)
        // so we can get n by, one 3 always and (n-3)/2 2s required


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t; 

    while (t--)
    {
        long long n, k, x;
        cin >> n >> k >> x;

        // Case 1: x != 1 
        // k is always greater than x, so if x!=1, then k>=1 anyways
        if (x != 1)
        {
            cout << "YES\n";
            cout << n << "\n";
            for (int i = 0; i < n; i++)
                cout << 1 << " ";
            cout << "\n";
        }
        else
        {
            // Case 2: x == 1

            // Subcase: k == 1 -> no numbers available
            // Subcase: k == 2 and n is odd -> only 2 available, can't make odd sum
            if (k == 1 || (k == 2 && n % 2 == 1))
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";

                // If n is even, use all 2s
                if (n % 2 == 0)
                {
                    cout << n / 2 << "\n";
                    for (int i = 0; i < n / 2; i++)
                        cout << 2 << " ";
                    cout << "\n";
                }
                else
                {
                    // n is odd and k >= 3
                    // Use one 3, rest 2s
                    cout << (n - 3) / 2 + 1 << "\n";
                    for (int i = 0; i < (n - 3) / 2; i++)
                        cout << 2 << " ";
                    cout << 3 << "\n";
                }
            }
        }
    }
    return 0;
}
