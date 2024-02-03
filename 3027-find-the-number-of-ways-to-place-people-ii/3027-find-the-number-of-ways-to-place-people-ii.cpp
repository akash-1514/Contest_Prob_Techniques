class Solution {
public:
    static bool cmp(vector<int>&v1, vector<int>&v2) {
        if(v1[0] == v2[0]) {
            return v1[1] > v2[1];
        } 
        return v1[0] < v2[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        sort(points.begin(), points.end(), cmp);
        
        for(int i = 0; i < n; ++i) {
            int maxY = INT_MIN;
            for(int j = i + 1; j < n; ++j) {
                if(points[i][1] >= points[j][1]) {
                    if(points[j][1] > maxY) {
                        ans++;
                        maxY = points[j][1];
                    }
                }
            }
        }
        return ans;
    }
};