class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> time;
        for(int i = 0; i < n; ++i) {
            int t = ceil(1.0 * dist[i] / speed[i]);
            time.push_back(t);
        }
        
        sort(time.begin(), time.end());
        
        int cnt = 0, ans = 0;
        for(int i = 0; i < n; ++i) {
            if(time[i] - cnt > 0) {
                ans++;
                cnt++;
            } else {
                break;
            }
        }
        return ans;
    }
};