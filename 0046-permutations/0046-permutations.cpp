class Solution {
public:
    vector<vector<int>>ans;
    vector<int> op;
    unordered_map<int, int>mp;
    void helper(vector<int>&arr) {
        if(op.size() == arr.size()) {
            ans.push_back(op);
            return;
        }
        
        for(int i = 0; i < arr.size(); ++i) {
            if(mp[arr[i]] > 0) continue;
            mp[arr[i]]++;
            op.push_back(arr[i]);
            helper(arr);
            op.pop_back();
            mp[arr[i]]--;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums);
        return ans;
    }
};