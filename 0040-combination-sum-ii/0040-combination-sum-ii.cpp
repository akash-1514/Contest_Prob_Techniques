class Solution {
public:
    vector<int>res;
    vector<vector<int>>ans;
    void helper(vector<int>&arr, int idx, int target) {
        if(target == 0) {
            ans.push_back(res);
            return;
        }
        if(idx == arr.size() || target < 0) {
            return;
        }
        
        res.push_back(arr[idx]);
        helper(arr, idx + 1, target - arr[idx]);
        res.pop_back();
        
        while(idx + 1 < arr.size() && arr[idx] == arr[idx + 1]) idx++;
        helper(arr, idx + 1, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target);
        return ans;
    }
};