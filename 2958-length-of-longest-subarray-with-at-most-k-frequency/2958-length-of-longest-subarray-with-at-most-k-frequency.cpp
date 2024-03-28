class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int mx = 0, i = 0;
        unordered_map<int, int>mp;
        for(int j = 0; j < nums.size(); ++j) {
            mp[nums[j]]++;
            while(mp[nums[j]] > k) {
                if(--mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            mx = max(mx, j - i + 1);
        }
        return mx;
    }
};