class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        for(auto &r : roads) {
            degree[r[0]]++;
            degree[r[1]]++;
        }
        
        vector<pair<int, int>> vec;
        for(int i = 0; i < n; ++i) {
            vec.push_back({degree[i], i});
        }
        
        sort(vec.begin(), vec.end());
        
        vector<int> values(n, 0);
        for(int i = n - 1; i >= 0; --i) {
            values[vec[i].second] = i + 1;
        }
        
        long long ans = 0;
        for(auto &r : roads) {
            ans += (values[r[0]] + values[r[1]]);
        }
        return ans;
    }
};