class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());
        vector<int> pre = meetings[0];
        vector<vector<int>> res;
        for(int i = 1; i < n; ++i) {
            if(meetings[i][0] <= pre[1]) {
                pre[1] = max(meetings[i][1], pre[1]);
            } else {
                res.push_back(pre);
                pre = meetings[i];
            }
        }
        res.push_back(pre);
        int cnt = 0;
        for(auto &m : res) {
            cnt += (m[1] - m[0] + 1);
        }
        return days - cnt;
    }
};