class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, unordered_set<int>>x_axis, y_axis;
        for(auto &p : points) {
            x_axis[p[0]].insert(p[1]);
            y_axis[p[1]].insert(p[0]);
        }
        
        int mn = 1e9;
        
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(points[i][1] == points[j][1]) {
                    for(auto &it : x_axis[points[i][0]]) {
                        if(it == points[i][1]) continue;
                        if(x_axis[points[j][0]].find(it) != x_axis[points[j][0]].end()) {
                            int l = abs(points[j][0] - points[i][0]);
                            int b = abs(points[j][1] - it);
                            mn = min(mn, l * b);
                        }
                    }
                } 
            }
        }
        
        return mn == 1e9 ? 0 : mn;
    }
};