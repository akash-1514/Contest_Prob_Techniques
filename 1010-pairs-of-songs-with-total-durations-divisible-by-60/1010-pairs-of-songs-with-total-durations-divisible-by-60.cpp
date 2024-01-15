class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        unordered_map<int, int>mp;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(time[i] % 60 == 0) {
                ans += mp[0];
            } else {
                ans += mp[60 - time[i] % 60];
            }
            mp[time[i] % 60]++;
        }
        return ans;
    }
};