class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), lastIdx = 0, mx = 1;
        vector<int> dp(n, 1), hash(n, 0);
        for(int i = 0; i < n; ++i) hash[i] = i;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[j] + 1 > dp[i]) {
                        hash[i] = j;
                        dp[i] = dp[j] + 1;
                    }
                }
            }
            if(dp[i] > mx) {
                mx = dp[i];
                lastIdx = i;
            }
        }
        
        vector<int>ans;
        while(hash[lastIdx] != lastIdx) {
            ans.push_back(nums[lastIdx]);
            lastIdx = hash[lastIdx];
        }
        ans.push_back(nums[lastIdx]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};