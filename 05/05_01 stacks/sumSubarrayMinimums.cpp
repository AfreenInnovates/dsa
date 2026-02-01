class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // const int MOD = 1e9 + 7;
        // brute force O(N cube)
        // find all sub arrays, take all minimums and add 
        // long long total = 0;
        // int n = arr.size();
        // for (int i = 0; i < n; i++) {
        //     for (int j=i; j < n; j++) {
        //         int mn = INT_MAX;
        //         for (int k = i; k <= j; k++) {
        //             mn=min(mn, arr[k]);
        //         }
        //         total+= mn;
        //     }
        // }
        // return total % MOD;


        // O(N square) (ran 87/88 test cases :( ))
        // for (int i = 0; i <n; i++) {
        //     int mn = arr[i];
        //     for (int j = i; j<n; j++) {
        //         mn = min(mn, arr[j]);
        //         total+=mn;
        //     }
        // }
        // return total%MOD;


        // using stacks 
        const int MOD = 1e9 + 7;
        int n = arr.size();

        vector<int> pse(n), nse(n);
        stack<int> st;
        
        // store previous smaller elements
        for (int i=0; i<n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();

            pse[i]= st.empty()?-1: st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // store next smaller elements
        for (int i=n-1; i>=0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans=0;
        for (int i=0; i<n;i++) {
            long long left = i-pse[i];
            long long right = nse[i]-i;

            long long contri = (arr[i] * left % MOD) * right % MOD;

            ans = (ans + contri) % MOD;
        }

        return (int)ans;
    }
};