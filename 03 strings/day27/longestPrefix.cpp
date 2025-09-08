#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty())
    {
        cout << "[DBG] strs is empty → return \"\"\n";
        return "";
    }

    string prefix = strs[0];
    cout << "[DBG] init prefix = \"" << prefix << "\"\n";

    for (int i = 1; i < (int)strs.size(); ++i)
    {
        cout << "[DBG] compare with strs[" << i << "] = \"" << strs[i] << "\"\n";

        while (strs[i].find(prefix) != 0)
        {
            cout << "      not a prefix → shrink: \"" << prefix << "\" → ";
            prefix = prefix.substr(0, prefix.length() - 1);
            cout << "\"" << prefix << "\"\n";

            if (prefix.empty())
            {
                cout << "[DBG] prefix became empty → return \"\"\n";
                return "";
            }
        }
        cout << "      OK, current prefix = \"" << prefix << "\"\n";
    }

    cout << "[DBG] final prefix = \"" << prefix << "\"\n";
    return prefix;
}

static void printVec(const vector<string> &v)
{
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << "\"" << v[i] << "\"";
        if (i + 1 < v.size())
            cout << ", ";
    }
    cout << "]";
}

int main()
{
    vector<vector<string>> tests = {
        {"flower", "flow", "flight"},
        {"dog", "racecar", "car"},
        {"interspecies", "interstellar", "interstate"},
        {"", "a"},
        {"alone"},
        {}};

    for (auto strs : tests)
    {
        cout << "Input: ";
        printVec(strs);
        cout << "\n";
        string res = longestCommonPrefix(strs);
        cout << "Output: \"" << res << "\"\n";
        cout << "--------------------------------------\n";
    }
    return 0;
}
