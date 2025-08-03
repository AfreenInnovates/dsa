#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 1. Basic push_back and emplace_back
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    cout << "Vector v: ";
    for (int val : v)
        cout << val << " ";
    cout << endl;

    // 2. Vector of pairs
    vector<pair<int, int>> vec;
    vec.push_back({3, 4});
    vec.emplace_back(5, 6);

    cout << "Vector of pairs vec:\n";
    for (auto p : vec)
        cout << "(" << p.first << ", " << p.second << ") ";
    cout << endl;

    // 3. Vector with predefined size and value
    vector<int> vec1(5, 100); // 5 values of 100

    cout << "Vector vec1 (5 values of 100): ";
    for (int val : vec1)
        cout << val << " ";
    cout << endl;

    // 4. Vector with size only (default-initialized to 0)
    vector<int> vec2(5); // 5 values of 0 (default int initialization)

    cout << "Vector vec2 (5 values default-initialized): ";
    for (int val : vec2)
        cout << val << " ";
    cout << endl;

    // 5. Copy constructor
    vector<int> vec3(vec2);

    cout << "Vector vec3 (copy of vec2): ";
    for (int val : vec3)
        cout << val << " ";
    cout << endl;

    // 6. Using iterator to traverse a vector of pairs
    cout << "Traversing vec using iterator:\n";
    for (vector<pair<int, int>>::iterator it = vec.begin(); it != vec.end(); ++it)
        cout << "(" << it->first << ", " << it->second << ") ";
    cout << endl;

    // 7. Vector initialized from array
    int arr[] = {10, 20, 30, 40};
    vector<int> vec4(arr, arr + 4);

    cout << "Vector vec4 (initialized from array): ";
    for (int val : vec4)
        cout << val << " ";
    cout << endl;

    // 8. Vector using initializer list
    vector<int> vec5 = {7, 8, 9};

    cout << "Vector vec5 (initializer list): ";
    for (int val : vec5)
        cout << val << " ";
    cout << endl;

    // 9. travering through a vector
    vector<int> vec_it = {0, 5, 10, 15, 20};
    vector<int>::iterator it;
    cout << "Traversing vec_it using iterator: ";
    for (it = vec_it.begin(); it != vec_it.end(); ++it)
    {
        cout << *it << " "; // Dereference the iterator to access value
    }
    // cout << endl;
    return 0;
}

// lists - push back time complexity < vector push back time complexity
