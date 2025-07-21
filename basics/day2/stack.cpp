#include <bits/stdc++.h>
using namespace std;

int main()
{
    // lifo - last in first out
    stack<int> st1;
    st1.push(1);
    st1.push(2);
    st1.push(3);
    st1.emplace(4);

    cout << st1.top() << endl;
    st1.pop();
    cout << st1.top() << endl;
    cout << st1.size() << endl;

    cout
        << st1.empty() << endl;
}