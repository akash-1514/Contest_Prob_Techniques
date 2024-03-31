class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();
        multiset<int>st1, st2;
        
        for(int i = 0; i < n; ++i) {
            st1.insert(points[i][0] + points[i][1]);
            st2.insert(points[i][0] - points[i][1]);
        }
        
        int mn = 1e9;
        for(int i = 0; i < n; ++i) {
            int a = points[i][0] + points[i][1], b = points[i][0] - points[i][1];
            st1.erase(st1.find(a));
            st2.erase(st2.find(b));
            int v1 = *st1.rbegin() - *st1.begin();
            int v2 = *st2.rbegin() - *st2.begin();
            mn = min(mn, max(v1, v2));
            st1.insert(a);
            st2.insert(b);
        }
        
        return mn;
    }
};