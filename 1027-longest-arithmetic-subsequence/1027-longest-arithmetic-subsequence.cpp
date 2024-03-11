class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, unordered_map<int, int>>dp;
        int ans = 0;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                int currDiff = nums[i] - nums[j];
                ans = max(ans, dp[j][currDiff] + 2);
                dp[i][currDiff] = max(dp[i][currDiff], 1 + dp[j][currDiff]);
            }
        }
        
        return ans;
    }
};