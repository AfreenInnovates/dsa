#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here

    int T;
    cin >> T;

    while (T--)
    {
        int X, Y, Z;

        cin >> X >> Y >> Z;

        // taking in no. of schools, no. of students in each school , no. of passed students

        // total students = no . of schools * no.of students in each school

        int total_students = X * Y;

        // we must check if, passed no. of students, is greater than half of total no. students
        if (Z > (total_students / 2))
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}
