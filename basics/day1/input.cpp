#include <iostream>
#include <bits/stdc++.h> // includes all libraries
using namespace std;

// int main()
// {
//     cout << "Hello, World!" << endl;

//     string name;
//     int x;

//     cout << "Enter a number: ";
//     cin >> x;
//     cout << "Enter a name: " << endl;
//     cin >> name;

//     cout << "Number: " << x << endl;
//     cout << "Name: " << name;

//     cout << "\n";
//     int dayNum;
//     cout << "Enter when you have to go to college: " << endl;
//     cin >> dayNum;

//     switch (dayNum)
//     {
//     case 1:
//         cout << "Sunday it is!";
//         break;

//     case 2:
//         cout << "Monday it is!";
//         break;

//     default:
//         cout << "Can stay at home!";
//         break;
//     }

//     return 0;
// }

// =============================================================================================================

// arrays passed in a function are always passed by reference
// for other data types, we must use '&' before variable name in the function definition to pass by reference

void funcs(int arr[], string &byRefStr, string byValStr)
{
    for (int i = 0; i < 5; i++)
    {
        arr[i] += 5;
    }

    cout << "\nArray after passing to function:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    byRefStr += " ok";
    byValStr += " ok2";

    cout << "String passed by reference (inside function): " << byRefStr << endl;
    cout << "String passed by value (inside function): " << byValStr << endl;
}

int main()
{
    int arr[5];
    string str;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter a number: ";
        cin >> arr[i];
    }

    cin.ignore();

    cout << "\n\nEnter a string: ";
    getline(cin, str);

    funcs(arr, str, str);

    cout << "String outside function value: " << str << endl;

    return 0;
}