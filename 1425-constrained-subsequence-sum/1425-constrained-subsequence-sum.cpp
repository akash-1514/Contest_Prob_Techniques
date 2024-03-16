class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size(), ans = -1e9;
        deque<int>dq;
        vector<int> dp(n, 0);
        for(int i = 0; i < n; ++i) {
            if(i <= k) {
                if(dq.empty()) {
                    dp[i] = nums[i];
                    dq.push_back(i);
                } else {
                    dp[i] = max(nums[i], nums[i] + dp[dq.front()]);
                    while(!dq.empty() && dp[dq.back()] < dp[i]) {
                        dq.pop_back();
                    }
                    dq.push_back(i);
                }
            } else {
                if(dq.front() == i - k - 1) {
                    dq.pop_front();
                } 
                dp[i] = max(nums[i], nums[i] + dp[dq.front()]);
                while(!dq.empty() && dp[dq.back()] < dp[i]) {
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};