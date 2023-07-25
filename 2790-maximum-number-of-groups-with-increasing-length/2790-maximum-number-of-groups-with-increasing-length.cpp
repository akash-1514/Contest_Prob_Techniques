class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        int n = usageLimits.size();
        sort(usageLimits.begin(), usageLimits.end());
        
        long long groups = 0, tot = 0;
        for(int i = 0; i < n; ++i) {
            tot += usageLimits[i];
            if(tot >= ((groups + 1) * 1ll * (groups + 2)) / 2) {
                groups++;
            }
        }
        return (int)groups;
    }
};