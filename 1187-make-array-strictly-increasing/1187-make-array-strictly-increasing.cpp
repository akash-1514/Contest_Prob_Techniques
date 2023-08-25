class Solution {
public:
    map<int, map<int, int>>dp;
    int helper(vector<int>&arr1, vector<int>&arr2, int idx, int prev) {
        if(idx >= arr1.size()) return 0;
        
        if(dp.find(idx) != dp.end() && dp[idx].find(prev) != dp[idx].end()) {
            return dp[idx][prev];
        }
        
        // not change
        int notChange = 1e9;
        if(arr1[idx] > prev) {
            notChange = helper(arr1, arr2, idx + 1, arr1[idx]);
        }
        
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        int change = 1e9;
        if(it != arr2.end()) {
            change = 1 + helper(arr1, arr2, idx + 1, *it);
        }
        return dp[idx][prev] = min(change, notChange);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        int res = helper(arr1, arr2, 0, -1);
        if(res == 1e9) return -1;
        return res;
    }
};