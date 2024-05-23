class Solution {
public:
    void helper(vector<int>&nums, int idx, int k, unordered_map<int, int>&mp, int &cnt) {
        if(idx >= nums.size()) {
            cnt++;
            return;
        }
        
        if(mp[nums[idx] - k] == 0 && mp[nums[idx] + k] == 0) {
            mp[nums[idx]]++;
            helper(nums, idx + 1, k, mp, cnt);
            mp[nums[idx]]--;
        }
        
        helper(nums, idx + 1, k, mp, cnt);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int cnt = 0;
        unordered_map<int, int>mp;
        helper(nums, 0, k, mp, cnt);
        return cnt - 1;
    }
};