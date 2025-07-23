#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout << "Enter length of array: ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter number: ";
        cin >> arr[i];
    }

    // creating the map
    map<int, int> mapNum;
    for (int i = 0; i < n; i++)
    {
        mapNum[arr[i]] += 1;
        // ex.:
        // arr[0] = 10
        // mapNum[arr[0]] += 1  ===> mapNum[10] = 1
    }

    int num;
    cout << "Enter number of numbers you want to enter: ";
    cin >> num;

    while (num--)
    {
        int number;
        cout << "Enter the number: ";
        cin >> number;

        cout << number << " occurs " << mapNum[number] << " times." << endl;
    }

    // iterate in the map
    for (auto it : mapNum)
    {
        cout << it.first << " ---> " << it.second << endl;
    }
}

// numbers are in sorted order
// we do not need to create an array of some size - so it is more memory efficient than hashing
