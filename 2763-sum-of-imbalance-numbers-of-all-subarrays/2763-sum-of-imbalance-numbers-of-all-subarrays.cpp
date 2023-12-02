class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; ++i) {
            unordered_set<int>st;
            int cnt = 0;
            for(int j = i; j < n; ++j) {
                if(st.find(nums[j]) != st.end()) {
                    ans += (cnt - 1);
                    continue;
                }
                st.insert(nums[j]);
                if(st.find(nums[j] + 1) == st.end()) {
                    cnt++;
                } 
                
                if(st.find(nums[j] - 1) != st.end()) {
                    cnt--;
                }
                
                ans += (cnt - 1);
            }
        }
        return ans;
    }
};