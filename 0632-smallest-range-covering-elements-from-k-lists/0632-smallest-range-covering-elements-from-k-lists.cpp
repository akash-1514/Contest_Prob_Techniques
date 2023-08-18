class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        
        set<int>st;
        for(int i = 0; i < n; ++i) {
            st.insert(nums[i][0]);
            pq.push({nums[i][0], {0, i}});
        }
        
        vector<int>ans;
        int len = 1e9;
        while(!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            
            int ele = tp.first, idx = tp.second.first, arr_n = tp.second.second;
            
            int mx = *st.rbegin();
            int mn = ele;
            
            if(mx - mn + 1 < len) {
                len = mx - mn + 1;
                ans = {mn, mx};
            } else if(mx - mn + 1 == len) {
                if(mn < ans[0]) {
                    ans = {mn, mx};
                }
            }
            
            // st.erase(ele);
            if(idx + 1 < nums[arr_n].size()) {
                pq.push({nums[arr_n][idx + 1], {idx + 1, arr_n}});
                st.insert(nums[arr_n][idx + 1]);
            } else {
                break;
            }
        }
        
        return ans;
    }
};