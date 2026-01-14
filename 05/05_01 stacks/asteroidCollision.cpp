class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        st.push(asteroids[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            int curr = asteroids[i];
            bool currAlive = true;

            while (!st.empty() && curr > 0 && st.top() < 0) {
                if (abs(curr) > abs(st.top()))
                    st.pop();
                else if (abs(curr) <
                         abs(st.top())) { // current is smaller than what's on
                                          // top, so we don't do anything and
                                          // move on to next asteroid
                    currAlive = false;
                    break;
                } else {      // equal size asteroids
                    st.pop(); // pop what's on top
                    currAlive =
                        false; // current asteroid is also destroyed -> no push
                    break;
                }
            }
            if (currAlive)
                st.push(curr);
        }

        vector<int> res(st.size());

        for (int i = 0; i < res.size(); i++) {
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};