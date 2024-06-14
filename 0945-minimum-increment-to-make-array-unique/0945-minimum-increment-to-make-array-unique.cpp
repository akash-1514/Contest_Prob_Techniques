class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> freq(n + mx + 1, 0);
        for(int ele : nums) freq[ele]++;
        int ans = 0;
        for(int i = 0; i < n + mx + 1; ++i) {
            if(freq[i] <= 1) continue;
            freq[i + 1] += (freq[i] - 1);
            ans += (freq[i] - 1);
            freq[i] = 1;
        }
        return ans;
    }
};