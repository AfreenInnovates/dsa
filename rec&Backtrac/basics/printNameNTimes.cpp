#include <bits/stdc++.h>
using namespace std;

// time : O(N)
// space : O(N) in computer memory
void printName(string name, int n, int i)
{
    if (i > n)
        return;
    cout << name << endl;
    printName(name, n, i + 1);
}

int main()
{
    int n;
    cout << "Enter number of times to print name: " << endl;
    cin >> n;
    cin.ignore();

    string name;
    cout << "Enter the name: " << endl;
    getline(cin, name);

    printName(name, n, 1);
    return 0;
}
