class Solution {
public:
    int countPairs(vector<vector<int>>& arr, int k) {
        int n = arr.size(), ans = 0;
        unordered_map<int, unordered_map<int, int>>mp;
        for(int i = 0; i < n; ++i) {
            int x1 = arr[i][0], y1 = arr[i][1];
            for(int j = 0; j <= k; ++j) {
                int b = k - j;
                int x2 = j ^ x1, y2 = b ^ y1;
                ans += mp[x2][y2];
            }
            mp[x1][y1]++;
        }
        
        return ans;
    }
};