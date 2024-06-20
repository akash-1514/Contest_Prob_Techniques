class Solution {
public:
    int dp[2001][2002];
    int helper(vector<int>&arr, int idx, int curr) {
        int n = arr.size();
        if(idx >= arr.size() || curr == arr[n - 1] + 1) {
            return 0;
        }
        
        if(dp[idx][curr] != -1) return dp[idx][curr];
        
        int mx = 0;
        if(curr < arr[idx]) {
            mx = max(mx, arr[idx] + helper(arr, idx + 1, min(curr + arr[idx], arr[n - 1] + 1)));
        }
        
        mx = max(mx, helper(arr, idx + 1, curr));
        return dp[idx][curr] = mx;
    }
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        memset(dp, -1, sizeof(dp));
        return helper(rewardValues, 0, 0);
    }
};