#include <iostream>
using namespace std;

int main()
{
    int A, B;
    if (cin >> A >> B)
    {
        if (A == B)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}