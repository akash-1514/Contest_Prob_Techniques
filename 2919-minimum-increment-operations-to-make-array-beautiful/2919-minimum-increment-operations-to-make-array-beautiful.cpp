class Solution {
public:
    long long dp[100001][3];
    long long helper(vector<int>&arr, int idx, int k, int cnt) {
        if(idx >= arr.size()) {
            return 0;
        }
        
        if(dp[idx][cnt] != -1) return dp[idx][cnt];
        
        long long mn = 1e18;
        
        if(cnt > 0) {
            mn = min(mn, max(0, k - arr[idx]) + helper(arr, idx + 1, k, 2));
            mn = min(mn, helper(arr, idx + 1, k, cnt - 1));
        } else {
            mn = min(mn, max(0, k - arr[idx]) + helper(arr, idx + 1, k, 2));
        }
        
        return dp[idx][cnt] = mn;
    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        long long mn = 1e18;
        for(int i = 0; i < 3; ++i) {
            if(nums[i] >= k) {
                mn = min(mn, helper(nums, i + 1, k, 2));
            } else {
                mn = min(mn, (k - nums[i]) + helper(nums, i + 1, k, 2));
            }
        }
        return mn;
    }
};