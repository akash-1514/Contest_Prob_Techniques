class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        map<int, int>mp;
        for(int i = 0; i <= n; ++i) {
            int l = max(0, i - ranges[i]);
            int r = min(n, i + ranges[i]);
            mp[l] = max(mp[l], r);
        }
        
        vector<vector<int>>vec;
        for(auto &it : mp) {
            vec.push_back({it.first, it.second});
        }
        
        int start = 0, idx = 0, ans = 0, mx = -1e9;
        while(idx < vec.size()) {
            if(vec[idx][0] <= start) {
                mx = max(mx, vec[idx][1]);
                idx++;
            } else {
                if(mx == -1e9 || mx <= start) return -1;
                else {
                    start = mx;
                    ans++, mx = -1e9;
                    if(start == n) break;
                }
            }
        }
        if(start == n) return ans;
        else {
            if(mx != -1e9 && mx == n) {
                return ++ans;
            }
            return -1;
        }
    }
};