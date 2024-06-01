class Solution {
public:
    void helper(vector<int>&nums, int idx, vector<int>&res, vector<vector<int>>&ans, unordered_map<int, int>&mp) {
        if(idx >= nums.size()) {
            ans.push_back(res);
            return;
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            if(mp.find(nums[i]) == mp.end()) {
                res.push_back(nums[i]);
                mp[nums[i]];
                helper(nums, idx + 1, res, ans, mp);
                mp.erase(nums[i]);
                res.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        unordered_map<int, int>mp;
        helper(nums, 0, res, ans, mp);
        return ans;
    }
};