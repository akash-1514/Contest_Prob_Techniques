//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1e9 + 7;
    vector<vector<int>>dp;
    int helper(vector<int>&arr, int idx, int k) {
        if(idx >= arr.size()) {
            return k == 0;
        }
        if(dp[idx][k] != -1) return dp[idx][k];
        int cnt = 0;
        if(k - arr[idx] >= 0) {
            cnt = (cnt + helper(arr, idx + 1, k - arr[idx])) % mod;
        }
        cnt = (cnt + helper(arr, idx + 1, k)) % mod;
        return dp[idx][k] = cnt;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        int tot = 0;
        for(int ele : arr) tot += ele;
        if(tot - d < 0 || (tot - d) % 2 != 0)  {
            return 0;
        }
        int k = (tot - d) / 2;
        dp.resize(n, vector<int>(k + 1, -1));
        return helper(arr, 0, k);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends