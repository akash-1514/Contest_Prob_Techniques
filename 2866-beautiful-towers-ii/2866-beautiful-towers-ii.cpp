#define ll long long
class Solution {
public:
    vector<ll> NSL(vector<int>&nums) {
        vector<ll>ans;
        stack<int>st;
        for(int i = 0; i < nums.size(); ++i) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
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
    
    vector<ll> NSR(vector<int>&nums) {
        vector<ll>ans;
        stack<int>st;
        for(int i = nums.size() - 1; i >= 0; --i) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
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
    
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<ll> nsr = NSR(maxHeights), nsl = NSL(maxHeights);
        vector<ll> left(n, 0), right(n, 0);
        left[0] = maxHeights[0];
        for(int i = 1; i < n; ++i) {
            int leftIdx = nsl[i];
            left[i] = ((i - leftIdx) * 1ll * maxHeights[i]) + ((leftIdx != -1) ? left[leftIdx] : 0);
        }
        
        right[n - 1] = maxHeights[n - 1];
        
        for(int i = n - 2; i >= 0; --i) {
            int rightIdx = nsr[i];
            right[i] = (rightIdx - i) * 1ll * maxHeights[i] + ((rightIdx != n) ? right[rightIdx] : 0);
        }
        
        
        ll mx = 0;
        for(int i = 0; i < n; ++i) {
            mx = max(mx, left[i] + right[i] - maxHeights[i]);
        }
        return mx;
    }
};