#include <bits/stdc++.h>
using namespace std;

void bruteApproach(vector<int> a, vector<int> b)
{
    int n1 = a.size();
    int n2 = b.size();

    set<int> st;

    // each insertion to a set takes O(log(n)) time
    // so inserting n1 items O(n1 log (n))
    for (int i = 0; i < n1; i++)
    {
        st.insert(a[i]);
    }

    // O(n2 log(n))
    for (int i = 0; i < n2; i++)
    {
        st.insert(b[i]);
    }

    // O(n1+n2) time
    // total time complexity: O((n1+n2) log(n1+n2)) + O(n1+n2)

    // total space complexity:
    // set takes O(n1+n2)
    // temp takes O(n1+n2) --> used for returning the answer, not for solving the answer
    vector<int> temp;
    for (auto i : st)
    {
        temp.push_back(i);
    }

    cout << "Union of arrays: ";
    for (int i : temp)
    {
        cout << i << " ";
    }
    cout << endl;
}

// time: O(n1+n2) : as we are going through all elements in each vector
// space: O(n1+n2) just to return the array
void optimalApproach(vector<int> a, vector<int> b)
{
    int n1 = a.size();
    int n2 = b.size();

    vector<int> unionArr;

    int i = 0, j = 0;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            if (unionArr.empty() || unionArr.back() != a[i])
                unionArr.push_back(a[i]);
            i++;
        }
        else if (b[j] < a[i])
        {
            if (unionArr.empty() || unionArr.back() != b[j])
                unionArr.push_back(b[j]);
            j++;
        }
        else
        {
            if (unionArr.empty() || unionArr.back() != a[i])
                unionArr.push_back(a[i]);
            i++;
            j++;
        }
    }

    while (i < n1)
    {
        if (unionArr.empty() || unionArr.back() != a[i])
            unionArr.push_back(a[i]);
        i++;
    }

    while (j < n2)
    {
        if (unionArr.empty() || unionArr.back() != b[j])
            unionArr.push_back(b[j]);
        j++;
    }

    cout << "Optimal Union of arrays: ";
    for (int x : unionArr)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    int n1, n2;

    cout << "Enter number of elements in array A: ";
    cin >> n1;
    vector<int> a(n1);
    cout << "Enter elements of array A:\n";
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }

    cout << "Enter number of elements in array B: ";
    cin >> n2;
    vector<int> b(n2);
    cout << "Enter elements of array B:\n";
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << "\n--- Results ---\n";
    bruteApproach(a, b);
    optimalApproach(a, b);

    return 0;
}
