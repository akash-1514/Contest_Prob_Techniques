class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<int> suffix(n, 0);
        suffix[n - 1] = events[n - 1][2];
        for(int i = n - 2; i >= 0; --i) {
            suffix[i] = max(suffix[i + 1], events[i][2]);
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int s = events[i][0], e = events[i][1], v = events[i][2];
            vector<int> vec = {e + 1, INT_MIN, INT_MIN};
            auto idx = lower_bound(events.begin(), events.end(), vec) - events.begin();
            if(idx < events.size()) {
                ans = max(ans, v + suffix[idx]);
            } else {
                ans = max(ans, v);
            }
        }
        return ans;
    }
};