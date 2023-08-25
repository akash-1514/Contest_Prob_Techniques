class Solution {
public:
    int dp[61][(1 << 16)];
    vector<vector<int>>choice;
    int helper(vector<int>&arr, int n, int idx, int mask) {
        if(idx >= arr.size()) {
            if(mask == (1 << n) - 1) {
                return 0;
            }
            return 1e9;
        }
        
        if(dp[idx][mask] != -1) return dp[idx][mask];
        
        int pick = 1 + helper(arr, n, idx + 1, mask | arr[idx]);
        int notPick = helper(arr, n, idx + 1, mask);
        
        if(pick < notPick) {
            choice[mask][idx] = 1;
        } else {
            choice[mask][idx] = 0;
        }
        
        return dp[idx][mask] = min(pick, notPick);
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        unordered_map<string, int>mp;
        for(int i = 0; i < n; ++i) {
            mp[req_skills[i]] = i;
        }
        
        vector<int>p;
        for(auto &v : people) {
            int mask = 0;
            for(auto &str : v) {
                mask |= (1 << mp[str]);
            }
            p.push_back(mask);
        }
        
        choice.resize((1 << 16), vector<int>(p.size(), 0));
        
        memset(dp, -1, sizeof(dp));
        cout << helper(p, n, 0, 0) << endl;
        vector<int>ans;
        int mask = 0;
        for(int i = 0; i < p.size(); ++i) {
            if(choice[mask][i]) {
                mask |= p[i];
                ans.push_back(i);
            }
            if(mask == (1 << n) - 1) break;
        }
        return ans;
    }
};