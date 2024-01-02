class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int mx = 0;
        unordered_map<int, int>mp;
        for(int ele : nums) {
            mx = max(mx, ++mp[ele]);
        }
        vector<vector<int>>ans(mx);
        int cnt = 0, row = 0;
        while(cnt < mp.size()) {
            for(auto &it : mp) {
                if(it.second > 0) {
                    ans[row].push_back(it.first);
                    if(--it.second == 0) cnt++;
                }
            }
            row++;
        }
        return ans;
    }
};