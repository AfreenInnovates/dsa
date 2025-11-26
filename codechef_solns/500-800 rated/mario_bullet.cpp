#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    // bullet -> X pixels per frame
    // wants to shoot a goomba -> Y pixels from him
    // X pixel -> 1 frame
    // Y pixel -> how many
    // time = y/x

    // to find:
    // time + (y/x) >= z

    int t;
    cin >> t;
    while (t--)
    {
        int X, Y, Z;
        cin >> X >> Y >> Z;

        int travel_time = Y / X;
        int wait_time = max(0, Z - travel_time);

        cout << wait_time << endl;
    }
}
