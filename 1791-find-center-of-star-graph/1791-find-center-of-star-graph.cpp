class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int m = edges.size();
        vector<int> degree(m + 2, 0);
        for(auto &e : edges) {
            degree[e[0]]++;
            degree[e[1]]++;
        }
        
        for(int i = 1; i <= m + 1; ++i) {
            if(degree[i] == m) {
                return i;
            }
        }
        
        return 1;
    }
};