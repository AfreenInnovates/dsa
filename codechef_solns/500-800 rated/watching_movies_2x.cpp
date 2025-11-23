#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here

    // total X minutes
    // has to complete the first Y minutes in twice the usual speed
    // it means, Y can be completed in Y/2 minutes = time_y
    // so total time taken would be X - (2 *time_y) + time_y

    int x, y;
    cin >> x >> y;

    int time_y = y / 2;

    int total_time = x - (2 * time_y) + time_y;

    cout << total_time << endl;
}