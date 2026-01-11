class Solution {
public:
    string simplifyPath(string path) {
        // using stack
        // string token = "";
        // stringstream ss(path);
        // stack<string> st;

        // while (getline(ss, token, '/')) {
        //     if (token == "" || token == ".")
        //         continue;
        //     if (token != "..")
        //         st.push(token);
        //     else if (!st.empty())
        //         st.pop();
        // }

        // if (st.empty())
        //     return "/";

        // string res = "";
        // while (!st.empty()) {
        //     res = "/" + st.top() + res;
        //     st.pop();
        // }

        // return res;

        // using vector
        vector<string> vt;
        string token = "";
        stringstream ss2(path);
        while (getline(ss2, token, '/')) {
            if (token == "." || token == "")
                continue;
            if (token == "..") {
                if (!vt.empty())
                    vt.pop_back();
            }

            else
                vt.push_back(token);
        }

        string res = "/";
        for (int i = 0; i < vt.size(); i++) {
            res += vt[i];
            if (i != vt.size() - 1)
                res += "/";
        }

        return res;
    }
};