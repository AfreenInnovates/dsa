#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
using namespace std;

static inline bool isNoZeroDigits(int x)
{
    if (x == 0)
        return false;
    while (x > 0)
    {
        if (x % 10 == 0)
            return false;
        x /= 10;
    }
    return true;
}

static inline bool isNoZeroString(int x)
{
    return to_string(x).find('0') == string::npos;
}

static inline void printAns(const string &name, int n, pair<int, int> p)
{
    cout << name << ": n=" << n << " -> [" << p.first << ", " << p.second << "]\n";
    assert(p.first + p.second == n);
    assert(isNoZeroDigits(p.first) && isNoZeroDigits(p.second));
}

// ===============================================================
// Approach 1: String-concatenation check (brute force)
/*
Time:  O(n * log n). For each a in [1..n-1], we build strings for a and (n-a)
       and scan for '0' across O(log n) digits.
Space: O(log n) per iteration (temporary strings), O(1) auxiliary overall.
Why:   Converting numbers to strings and scanning digits costs proportional
       to digit count; we may try up to n-1 candidates.
*/
pair<int, int> getNoZero_pair_stringConcat(int n)
{
    for (int a = 1; a < n; ++a)
    {
        int b = n - a;
        // One-liner that ensures both have no '0' digit:
        if ((to_string(a) + to_string(b)).find('0') == string::npos)
        {
            return {a, b};
        }
    }
    return {-1, -1}; // should not happen per problem guarantee
}

// ===============================================================
// Approach 2: arithmetic digit-check (brute force, no strings)
/*
Time:  O(n * log n). For each a, digit-check a and (n-a) via %10/div10 (O(log n)).
Space: O(1). No allocations; constant extra variables.
Why:   Each digit-check is linear in digit count; we may test up to n-1 pairs.
*/
pair<int, int> getNoZero_pair_digitCheck(int n)
{
    for (int a = 1; a < n; ++a)
    {
        int b = n - a;
        if (isNoZeroDigits(a) && isNoZeroDigits(b))
        {
            return {a, b};
        }
    }
    return {-1, -1}; // should not happen per problem guarantee
}

// ===============================================================
// Approach 3: Skip candidates with zeros for 'a'
/*
Idea:   Iterate only over a values that already have no zero digits, then set b = n - a
        and only check b. This typically reduces the number of iterations
        (since many integers contain a '0'), especially as digit-length grows.

Time:   Worst-case still O(n * log n) (if many a’s are zero-free).
        In practice fewer iterations because we skip a’s with zeros.
Space:  O(log n) if implemented with strings for the jump; can be made O(1) with pure math.
Why:    We reduce iteration count by skipping blocks of numbers that contain '0' in 'a'.
        Each step still costs O(log n) to check b (and to jump).
*/

// Jump to the next number >= x that has no zero digits (string-based, O(log n))
static inline int nextNoZero(int x)
{
    string s = to_string(x);
    size_t pos = s.find('0');
    if (pos == string::npos)
        return x;                               // already no-zero
    s[pos] = '1';                               // bump the first '0' to '1'
    for (size_t j = pos + 1; j < s.size(); ++j) // and set all trailing digits to '1'
        s[j] = '1';
    return stoi(s);
}

pair<int, int> getNoZero_pair_skipA(int n)
{
    int a = nextNoZero(1);
    while (a < n)
    {
        int b = n - a;
        if (isNoZeroDigits(b))
            return {a, b};
        a = nextNoZero(a + 1);
    }
    return {-1, -1};
}

int main()
{
    vector<int> tests = {
        2,
        11,
        101,
        1002,
        9999};

    for (int n : tests)
    {
        auto p1 = getNoZero_pair_stringConcat(n);
        printAns("Approach 1 (string+find)", n, p1);

        auto p2 = getNoZero_pair_digitCheck(n);
        printAns("Approach 2 (digit-check)", n, p2);

        auto p3 = getNoZero_pair_skipA(n);
        printAns("Approach 3 (skip-a)", n, p3);

        cout << "----\n";
    }

    cout << "All checks passed.\n";
    return 0;
}
