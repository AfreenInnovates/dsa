#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

/*
Approach 1: Counter trick (single pass)
--------------------------------------
Idea: Maintain a nesting counter. On ')', decrement first; on '(' increment after.
      Append current char only when the counter is non-zero (i.e., we are inside
      a primitive and not at its outer boundary).

Time  : O(n) — each character processed once.
Space : O(1) auxiliary — aside from the output string.
Why   : Constant extra state (an int counter); no stack or extra containers needed.
*/
string removeOuterParentheses_counter(const string &s)
{
    string ans;
    ans.reserve(s.size());
    int depth = 0;
    for (char c : s)
    {
        if (c == ')')
            --depth;
        if (depth != 0)
            ans.push_back(c);
        if (c == '(')
            ++depth;
    }
    return ans;
}

/*
Approach 2: Explicit stack (brute-force baseline)
-------------------------------------------------
Idea: Simulate nesting with a stack. For '(', if stack not empty, append; then push.
      For ')', pop first; if stack still not empty, append.

Time  : O(n) — each character pushes/pops at most once.
Space : O(n) — stack can grow to current max depth; output also O(n).
Why   : Stack stores parentheses for nesting simulation, which can be linear in worst case.
*/
string removeOuterParentheses_stack(const string &s)
{
    string ans;
    ans.reserve(s.size());
    vector<char> st;
    for (char c : s)
    {
        if (c == '(')
        {
            if (!st.empty())
                ans.push_back('(');
            st.push_back('(');
        }
        else
        { // ')'
            st.pop_back();
            if (!st.empty())
                ans.push_back(')');
        }
    }
    return ans;
}

/*
Approach 3: Slice primitives by balance
---------------------------------------
Idea: Track balance; when it returns to 0, a primitive [start..i] ended.
      Append its inner part (start+1 .. i-1) to the answer.

Time  : O(n) — single pass; total copied characters ≤ n.
Space : O(1) auxiliary — aside from the output string.
Why   : We only keep counters/indices; no extra containers proportional to input.
*/
string removeOuterParentheses_slice(const string &s)
{
    string ans;
    ans.reserve(s.size());
    int bal = 0, start = 0;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        bal += (s[i] == '(' ? 1 : -1);
        if (bal == 0)
        { // primitive closed: [start..i]
            if (i - start + 1 >= 2)
                ans.append(s, start + 1, i - start - 1);
            start = i + 1;
        }
    }
    return ans;
}

int main()
{
    vector<string> tests = {
        "",
        "()",
        "()()",
        "(())",
        "(()())(())",
        "(()())(())(()(()))"};

    for (const auto &s : tests)
    {
        auto a1 = removeOuterParentheses_counter(s);
        auto a2 = removeOuterParentheses_stack(s);
        auto a3 = removeOuterParentheses_slice(s);

        cout << "s = \"" << s << "\"\n";
        cout << "  Counter : \"" << a1 << "\"\n";
        cout << "  Stack   : \"" << a2 << "\"\n";
        cout << "  Slice   : \"" << a3 << "\"\n\n";

        assert(a1 == a2 && a2 == a3);
    }

    cout << "All tests passed.\n";
    return 0;
}
