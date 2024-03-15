class Solution {
private:
    vector<long long>prefix, suffix;
public:
    long long func(vector<int>&nums, int s, int e) {
        int mid = (s + e) / 2;
        long long leftSum = 0, rightSum = 0;
        if(mid > 0) {
            leftSum = prefix[mid - 1];
            if(s > 0) {
                leftSum -= prefix[s - 1];
            }
        }
        if(mid < nums.size() - 1) {
            rightSum = suffix[mid + 1];
            if(e < nums.size() - 1) {
                rightSum -= suffix[e + 1];
            }
        }
        
        long long score = ((mid - s) * 1ll * nums[mid] - leftSum);
        score += (rightSum - ((e - mid) * 1ll * nums[mid]));
        return score;
    }
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        prefix.resize(n, 0), suffix.resize(n, 0);
        prefix[0] = nums[0], suffix[n - 1] = nums[n - 1];
        for(int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i];
            suffix[n - i - 1] = suffix[n - i] + nums[n - i - 1];
        }
        
        int i = 0, mx = 0;
        for(int j = 0; j < nums.size(); ++j) {
            while(func(nums, i, j) > k) {
                i++;
            }
            mx = max(mx, j - i + 1);
        }
        return mx;
    }
};