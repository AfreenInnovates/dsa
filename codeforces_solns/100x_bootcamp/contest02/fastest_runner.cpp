// In an Olympic race, there are N
//  runners numbered from 1
//  to N
// .

// You are given the time taken by each runner to complete the race.

// The runner with the minimum time is considered the fastest.

// If multiple runners have the same fastest time, choose the runner with the larger ID.

// approach 1:
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>arr(n);
    
    for (int i=0; i<n;i++) cin>>arr[i];
    
    map<int , int>times;

    for(int i = 0; i < n; i++) {
        times[i+1] = arr[i];
    }

    int mini = INT_MAX;
    for(auto &p : times) {
        mini = min(mini, p.second);
    }

    for (auto it =times.rbegin(); it!= times.rend(); ++it) {
        if (it->second == mini) {
            cout << it->first<<endl;
            break;
        }
    }

    return 0;
}



// approach 2: get the mini, then traverse from the back and find the position of the largest index
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int mini = *min_element(arr.begin(), arr.end());

    for(int i = n-1; i >= 0; i--) {
        if(arr[i] == mini) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}
