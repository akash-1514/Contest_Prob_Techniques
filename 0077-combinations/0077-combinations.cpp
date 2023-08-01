class Solution {
public:
    void helper(int n, int k, int idx, vector<int>&res, vector<vector<int>>&ans) {
        if(k == 0) {
            ans.push_back(res);
            return;
        }
        if(idx > n) {
            return;
        }
        
        res.push_back(idx);
        helper(n, k - 1, idx + 1, res, ans);
        res.pop_back();
        
        helper(n, k, idx + 1, res, ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>res;
        helper(n, k, 1, res, ans);
        return ans;
    }
};