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

    // creating the hash array
    int hash[13] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
        // ex.:
        // arr[0] = 10
        // hash[arr[0]] += 1  ===> hash[10] = 1  ===> that particular number's index increases by 1
    }

    int num;
    cout << "Enter number of numbers you want to enter: ";
    cin >> num;

    while (num--)
    {
        int number;
        cout << "Enter the number: ";
        cin >> number;

        cout << number << " occurs " << hash[number] << " times." << endl;
        ;
    }
}

// upto 10^6 size of int array can be decaled in 'main' function
// declaring globally, the size of int array can be upto 10^7