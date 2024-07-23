class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<pair<int, int>> vec;
        for(int i = 0; i < n;) {
            int curr = nums[i], cnt = 0;
            while(i < n && curr == nums[i]) {
                i++, cnt++;
            }
            vec.push_back({curr, cnt});
        }
        
        vector<int> prev(k + 1, 0);
        unordered_map<int, unordered_map<int, int>> same;
        
        for(int i = 0; i <= k; ++i) {
            prev[i] = vec[0].second;
            same[vec[0].first][i] = vec[0].second;
        }
        
        for(int i = 1; i < vec.size(); ++i) {
            vector<int> curr(k + 1, 0);
            for(int j = 0; j <= k; ++j) {
                int mx = 0;
                if(same.find(vec[i].first) != same.end()) {
                    mx = max(mx, same[vec[i].first][j] + vec[i].second);
                    same[vec[i].first][j] += vec[i].second;
                }
                
                mx = max(mx, ((j > 0) ? prev[j - 1] : 0) + vec[i].second);
                same[vec[i].first][j] = max(same[vec[i].first][j], ((j > 0) ? prev[j - 1] : 0) + vec[i].second);
                
                curr[j] = max(mx, prev[j]);
            }
            prev = curr;
        }
        
        int ans = 0;
        for(int ele : prev) {
            ans = max(ans, ele);
        }
        return ans;
    }
};