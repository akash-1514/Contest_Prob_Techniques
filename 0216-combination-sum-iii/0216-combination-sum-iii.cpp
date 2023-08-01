class Solution {
public:
    vector<int>res;
    vector<vector<int>>ans;
    void helper(int n, int k, int idx) {
        if(k == 0) {
            if(n == 0) {
                ans.push_back(res);
            }
            return;
        }

        if(idx > 9 || n < 0) return;
        
        res.push_back(idx);
        helper(n - idx, k - 1, idx + 1);
        res.pop_back();
        
        helper(n, k, idx + 1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        helper(n, k, 1);
        return ans;
    }
};