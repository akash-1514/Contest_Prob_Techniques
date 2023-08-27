class Solution {
private:
    const int mod = 1e9 + 7;
public:
    long long binpow(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());    
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(target - nums[i] >= nums[i]) {
                int idx = upper_bound(nums.begin(), nums.end(), target - nums[i]) - nums.begin();
                ans = (ans + binpow(2, idx - i - 1, mod)) % mod;
            }
        }
        return ans;
    }
};