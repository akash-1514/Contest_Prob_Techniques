class Solution {
public:
    int dp[100001];
    bool helper(vector<int>&arr, int idx) {
        int n = arr.size();
        if(idx >= n) return true;
        
        // check for memo
        if(dp[idx] != -1) return dp[idx];
        
        // check for two equal element
        if(idx + 1 < n && arr[idx] == arr[idx + 1]) {
            if(helper(arr, idx + 2)) return dp[idx] = true;
        }
        // check for three equal element
        if(idx + 2 < n && arr[idx] == arr[idx + 1] && arr[idx + 1] == arr[idx + 2]) {
            if(helper(arr, idx + 3)) return dp[idx] = true;
        }
        // check for increasing in three elements
        if(idx + 2 < n && arr[idx] + 1 == arr[idx + 1] && arr[idx + 1] + 1 == arr[idx + 2]) {
            if(helper(arr, idx + 3)) return dp[idx] = true;
        }
        return dp[idx] = false;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(nums, 0);
    }
};