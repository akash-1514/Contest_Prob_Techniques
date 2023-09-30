class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int, int>>st;
        int mx = INT_MIN;
        for(int i = n - 1; i >= 0; --i) {
            while(!st.empty() && st.top().first < nums[i]) {
                mx = max(mx, st.top().first);
                st.pop();
            }
            if(!st.empty() && mx > nums[i]) return true;
            st.push({nums[i], mx});
        }
        return false;
    }
};