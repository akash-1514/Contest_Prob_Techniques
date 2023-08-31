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
        
        int start = 0, idx = 0, ans = 0;
        priority_queue<int>pq;
        while(idx < vec.size()) {
            if(vec[idx][0] <= start) {
                pq.push(vec[idx][1]);
                idx++;
            } else {
                if(pq.empty() || pq.top() <= start) return -1;
                else {
                    start = pq.top();
                    pq.pop();
                    ans++;
                    if(start == n) break;
                }
            }
        }
        if(start == n) return ans;
        else {
            if(!pq.empty() && pq.top() == n) {
                return ++ans;
            }
            return -1;
        }
    }
};