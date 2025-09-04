#include <iostream>
#include <cmath>

using namespace std;

int findClosest(int x, int y, int z)
{
    int d1 = abs(z - x), d2 = abs(z - y);
    return (d1 == d2) ? 0 : (d1 < d2 ? 1 : 2);
}

int main()
{
    int x, y, z;
    cout << "Enter x, y, z: ";
    cin >> x >> y >> z;

    int result = findClosest(x, y, z);

    if (result == 1)
    {
        cout << "x (" << x << ") is closer to z (" << z << ")." << endl;
    }
    else if (result == 2)
    {
        cout << "y (" << y << ") is closer to z (" << z << ")." << endl;
    }
    else
    {
        cout << "Both x and y are equally close to z (" << z << ")." << endl;
    }

    return 0;
}
