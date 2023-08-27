class Solution {
public:
    vector<int>vis;
    bool helper(int n, int cnt, int idx, vector<int>&res) {
        if(cnt == n) {
            return true;
        }
        
        if(res[idx] == 0) {
            for(int i = n; i >= 1; --i) {
                if(vis[i] == 0) {
                    if(i == 1) {
                        res[idx] = 1;
                        vis[i] = 1;
                        if(helper(n, cnt + 1, idx + 1, res)) return true;
                        vis[i] = 0;
                        res[idx] = 0;
                    } else if(i > 1 && idx + i < 2 * n - 1 && res[idx + i] == 0) {
                        res[idx] = res[idx + i] = i;
                        vis[i] = 1;
                        if(helper(n, cnt + 1, idx + 1, res)) return true;
                        vis[i] = 0;
                        res[idx] = res[idx + i] = 0;
                    }
                }
            }
        } else {
            if(helper(n, cnt, idx + 1, res)) return true;
        }
        
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vis.resize(n + 1, 0);
        vector<int> res(2 * n - 1, 0);
        helper(n, 0, 0, res);
        return res;
    }
};