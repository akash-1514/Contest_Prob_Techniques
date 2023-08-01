class Solution {
private:
    vector<vector<int>>ans;
    vector<int>res;
public:
    void helper(vector<int>&arr, int idx, int target) {
        if(target == 0) {
            ans.push_back(res);
            return;
        }
        if(idx >= arr.size() || target < 0) {
            return;
        }
        
        res.push_back(arr[idx]);
        helper(arr, idx, target - arr[idx]);
        res.pop_back();
        
        helper(arr, idx + 1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates, 0, target);
        return ans;
    }
};