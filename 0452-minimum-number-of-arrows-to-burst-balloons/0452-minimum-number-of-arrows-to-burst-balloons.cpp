class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        
        int cnt = 1;
        int l = points[0][0], r = points[0][1];
        for(int i = 1; i < n; ++i) {
            if(points[i][0] <= r) {
                l = max(l, points[i][0]);
                r = min(r, points[i][1]);
            } else {
                cnt++;
                l = points[i][0], r = points[i][1];
            }
        }
        return cnt;
    }
};