class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int, int>>dq;
        dq.push_back({nums[n - 1], n - 1});
        int ans = nums[n - 1];
        for(int i = n - 2; i >= 0; --i) {
            while(!dq.empty() && dq.front().second > min(i + k, n - 1)) {
                dq.pop_front();
            }
            ans = nums[i] + dq.front().first;
            while(!dq.empty() && dq.back().first < ans) {
                dq.pop_back();
            }
            dq.push_back({ans, i});
        }
        return ans;
    }
};