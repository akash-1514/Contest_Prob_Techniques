class Solution {
public:
    int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for(int i = 0; i < n; ++i) {
            pq.push({nums[i], i + 1});
        }
        
        int ans = 0;
        
        for(int i = 1; i <= right; ++i) {
            auto front = pq.top();
            pq.pop();
            
            int num = front.first, idx = front.second;
            
            if(i >= left) {
                ans = (ans + num) % mod;
            } 
            
            if(idx < n) {
                pq.push({num + nums[idx], idx + 1});
            }
        }
        
        return ans;
    }
};