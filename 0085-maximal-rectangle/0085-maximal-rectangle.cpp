class Solution {
public:
    vector<int> NSR(vector<int>&nums) {
        vector<int>ans;
        stack<int>st;
        for(int i = nums.size() - 1; i >= 0; --i) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if(st.empty()) {
                ans.push_back(nums.size());
            } else {
                ans.push_back(st.top());
            }
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    vector<int> NSL(vector<int>&nums) {
        vector<int>ans;
        stack<int>st;
        for(int i = 0; i < nums.size(); ++i) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if(st.empty()) {
                ans.push_back(-1);
            } else {
                ans.push_back(st.top());
            }
            st.push(i);
        }
        return ans;
    }
    
    int calculate(vector<int>&nums) {
        vector<int> nsl = NSL(nums);
        vector<int> nsr = NSR(nums);
        
        int mx = 0;
        for(int i = 0; i < nums.size(); ++i) {
            mx = max(mx, nums[i] * (nsr[i] - nsl[i] - 1));
        }
        return mx;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> vec(m, 0);
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(matrix[i][j] == '0') vec[j] = 0;
                else vec[j]++;
            }
            
            ans = max(ans, calculate(vec));
        }
        return ans;
    }
};