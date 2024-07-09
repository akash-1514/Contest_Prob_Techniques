class Solution {
public:
    bool helper(vector<int>&ans, int n, int idx, int vis) {
        if(idx >= ans.size()) {
            return true;
        }
        
        if(ans[idx] == 0) {
            // place the ith element 
            for(int i = n; i >= 1; --i) {
                if((vis & (1 << i)) == 0) {
                    if(i != 1) {
                        if(idx + i < ans.size()) {
                            if(ans[idx + i] == 0) {
                                ans[idx] = i;
                                ans[idx + i] = i;
                                if(helper(ans, n, idx + 1, (vis | (1 << i)))) return true;
                                ans[idx] = 0;
                                ans[idx + i] = 0;
                            }
                        }
                    } else {
                        ans[idx] = 1;
                        if(helper(ans, n, idx + 1, (vis | (1 << i)))) return true;
                        ans[idx] = 0;
                    }
                }
            }
        } else {
            if(helper(ans, n, idx + 1, vis)) return true;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        int size = 2 * (n - 1) + 1;
        vector<int> ans(size, 0);
        helper(ans, n, 0, 0);
        return ans;
    }
};