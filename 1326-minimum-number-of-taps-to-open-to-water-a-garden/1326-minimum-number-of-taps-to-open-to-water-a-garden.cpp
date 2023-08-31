class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>>vec;
        for(int i = 0; i <= n; ++i) {
            int l = max(0, i - ranges[i]);
            int r = min(n, i + ranges[i]);
            vec.push_back({l, r});
        }
        
        sort(vec.begin(), vec.end());
        
        int taps = 0, maxEnd = -1e9, currPos = 0, idx = 0, ans = 0;
        
        while(idx <= n) {
            if(vec[idx][0] <= currPos) {
                maxEnd = max(maxEnd, vec[idx][1]);
                idx++;
            } else {
                if(maxEnd == -1e9 || maxEnd <= currPos) return -1;
                else {
                    ans++, currPos = maxEnd;
                    maxEnd = -1e9;
                    if(currPos == n) return ans;
                }
            }
        }
        return maxEnd == n ? ans + 1 : -1;
    }
};