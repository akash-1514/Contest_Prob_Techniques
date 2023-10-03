class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int>mp;
        for(int i = 0; i < n; ++i) {
            ans += mp[nums[i]];
            mp[nums[i]]++;
        }
        return ans;
    }
};