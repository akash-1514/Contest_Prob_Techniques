class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        vector<pair<int, int>> vec;
        for(int i = 0; i < n; ++i) {
            vec.push_back({difficulty[i], profit[i]});
        }
        sort(vec.begin(), vec.end());
        sort(worker.begin(), worker.end());
        int i = 0, j = 0, mx = 0, ans = 0;
        while(i < worker.size()) {
            while(j < n && vec[j].first <= worker[i]) {
                mx = max(mx, vec[j].second);
                j++;
            }
            ans += mx;
            i++;
        }
        return ans;
    }
};