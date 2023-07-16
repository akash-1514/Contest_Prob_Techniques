class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        int del = n - k;
        stack<int>st;
        for(int i = 0; i < nums.size(); ++i) {
            while(!st.empty() && st.top() > nums[i] && del != 0) {
                st.pop();
                del--;
            }
            st.push(nums[i]);
        }
        while(!st.empty() && del != 0) {
            st.pop();
            del--;
        }
        vector<int>ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};