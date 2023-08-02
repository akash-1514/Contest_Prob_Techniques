class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>&arr, int idx) {
        if(idx >= arr.size()) {
            ans.push_back(arr);
            return;
        }
        
        for(int i = idx; i < arr.size(); ++i) {
            swap(arr[i], arr[idx]);
            helper(arr, idx + 1);
            swap(arr[i], arr[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, 0);
        return ans;
    }
};