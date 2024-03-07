class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int>ans;
        queue<pair<int, int>>q;
        q.push({0, 0});
        set<pair<int, int>>st;
        st.insert({0, 0});
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto front = q.front();
                q.pop();
                
                int x = front.first, y = front.second;
                ans.push_back(nums[x][y]);
                
                if(x + 1 < n && y < nums[x + 1].size() && st.find({x + 1, y}) == st.end()) {
                    st.insert({x + 1, y});
                    q.push({x + 1, y});
                }
                
                if(y + 1 < nums[x].size() && st.find({x, y + 1}) == st.end()) {
                    st.insert({x, y + 1});
                    q.push({x, y + 1});
                }
            }
        }
        return ans;
    }
};