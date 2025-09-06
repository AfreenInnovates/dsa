#include <bits/stdc++.h>
using namespace std;

/*
 * 1) Manual loop with index + push_back
 * Time:  O(n)            Space: O(1) extra (returns a copy)
 */
string concat_push_back(string s1, const string &s2)
{
    for (size_t i = 0; i < s2.size(); ++i)
        s1.push_back(s2[i]);
    return s1;
}

/*
 * 2) Manual loop with iterators + push_back
 * Time:  O(n)            Space: O(1) extra
 */
string concat_iter_loop(string s1, const string &s2)
{
    for (char c : s2)
        s1.push_back(c);
    return s1;
}

/*
 * 3) operator+ (creates a new string)
 * Time:  O(n)            Space: O(n) (builds a new result)
 */
string concat_plus(const string &s1, const string &s2)
{
    return s1 + s2;
}

/*
 * 4) operator+= (mutates left string)
 * Time:  O(n)            Space: O(1) amortized
 */
string concat_plus_equal(string s1, const string &s2)
{
    s1 += s2;
    return s1;
}

/*
 * 5) string::append (mutates left string)
 * Time:  O(n)            Space: O(1) amortized
 */
string concat_append(string s1, const string &s2)
{
    s1.append(s2);
    return s1;
}

/*
 * 6) string::insert at end iterator (mutates left string)
 * Time:  O(n)            Space: O(1) amortized
 */
string concat_insert_end(string s1, const string &s2)
{
    s1.insert(s1.end(), s2.begin(), s2.end());
    return s1;
}

/*
 * 7) std::copy + back_inserter (mutates left string)
 * Time:  O(n)            Space: O(1) amortized
 */
string concat_copy_back_inserter(string s1, const string &s2)
{
    // (Optional optimization) reserve once to avoid re-allocations
    s1.reserve(s1.size() + s2.size());
    std::copy(s2.begin(), s2.end(), std::back_inserter(s1));
    return s1;
}

/*
 * 8) string::append with pointer/length (useful for substrings/buffers)
 * Time:  O(n)            Space: O(1) amortized
 */
string concat_append_span(string s1, const string &s2)
{
    s1.append(s2.data(), s2.size());
    return s1;
}

/*
 * 9) stringstream (handy when mixing many pieces/types)
 * Time:  O(n)            Space: O(n) (buffer inside stream)
 */
string concat_stringstream(const string &s1, const string &s2)
{
    ostringstream oss;
    oss << s1 << s2;
    return oss.str();
}

int main()
{
    string s1, s2;

    cout << "Enter first string: ";
    getline(cin, s1);
    cout << "Enter second string: ";
    getline(cin, s2);

    cout << "\n--- Concatenation methods ---\n";
    cout << "1) push_back (index)       : " << concat_push_back(s1, s2) << '\n';
    cout << "2) push_back (range-for)   : " << concat_iter_loop(s1, s2) << '\n';
    cout << "3) operator+               : " << concat_plus(s1, s2) << '\n';
    cout << "4) operator+=              : " << concat_plus_equal(s1, s2) << '\n';
    cout << "5) append                  : " << concat_append(s1, s2) << '\n';
    cout << "6) insert at end           : " << concat_insert_end(s1, s2) << '\n';
    cout << "7) copy + back_inserter    : " << concat_copy_back_inserter(s1, s2) << '\n';
    cout << "8) append(data, size)      : " << concat_append_span(s1, s2) << '\n';
    cout << "9) stringstream            : " << concat_stringstream(s1, s2) << '\n';

    return 0;
}
