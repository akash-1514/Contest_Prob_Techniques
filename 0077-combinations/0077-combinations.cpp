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
        
        for(int i = idx; i <= n; ++i) {
            res.push_back(i);
            helper(n, k - 1, i + 1, res, ans);
            res.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>res;
        helper(n, k, 1, res, ans);
        return ans;
    }
};