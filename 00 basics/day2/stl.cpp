#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int, int> p = {1, 2};
    cout << "p first: " << p.first << " ; p second: " << p.second << endl;

    pair<int, pair<int, int>> l = {1, {2, 3}};
    cout << "l first: " << l.first << " ; l.second.first: " << l.second.first << " ; l.second.second: " << l.second.second << endl;

    pair<int, int> arr1[] = {{1, 2}, {3, 4}, {5, 6}}; // declaring an array of pair<int, int>. So two elements per array
    cout << "arr1[0].first " << arr1[0].first << " ; arr1[1].second " << arr1[1].second;
}