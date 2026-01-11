class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> days(n,0);
        // approach that comes first in mind O(N square) :
        // for (int i = 0; i < n; i++) {
        //     int j = i + 1;
        //     while (j < n && temperatures[j] <= temperatures[i]) {
        //         j++;
        //     }
        //     if (j<n) days[i] = j-i;
        //     else days[i]=0;
        // }
        // return days;

        
        // stack approach
        stack<int> st;
        for (int i = n-1;i>=0;i--) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            if (!st.empty()) {
                days[i] = st.top() - i;
            }
            st.push(i);
        }
        return days;
    }
};