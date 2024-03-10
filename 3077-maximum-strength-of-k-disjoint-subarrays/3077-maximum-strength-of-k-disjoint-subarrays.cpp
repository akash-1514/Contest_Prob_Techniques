class Solution {
public:
    vector<vector<vector<long long>>>dp;
    long long helper(vector<int>&nums, int idx, int k, bool fl) {
        if(k == 0) return 0;
        if(idx >= nums.size()) {
            if(fl && k == 1) return 0;
            return -1e15;
        }
        
        if(dp[idx][k][fl] != -1e16) return dp[idx][k][fl];
        
        long long mx = -1e15;
        
        if(fl) {
            // continuing picking the elements
            long long score = ((k % 2 != 0) ? 1 : -1) * 1ll * nums[idx] * k;
            long long res = helper(nums, idx + 1, k, fl);
            if(res != -1e15) {
                mx = max(mx, score + res);
            }
            // break the subarray
            mx = max(mx, helper(nums, idx, k - 1, false));
        } else {
            // continuing skipping element
            mx = max(mx, helper(nums, idx + 1, k, fl));
            // start to include new subarray to ans
            long long res = helper(nums, idx + 1, k, true);
            if(res != -1e15) {
                long long score = ((k % 2 != 0) ? 1 : -1) * 1ll * nums[idx] * k;
                mx = max(mx, score + res);
            }
        }
        
        return dp[idx][k][fl] = mx;
    }
    long long maximumStrength(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return 0;
        
        dp.resize(n, vector<vector<long long>>(k + 1, vector<long long>(2, -1e16)));
        return helper(nums, 0, k, false);
    }
};