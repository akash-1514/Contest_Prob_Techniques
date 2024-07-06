class Solution {
public:
    int calc(vector<int>&bits, int len) {
        int res = 0;
        for(int i = 0; i < 32; ++i) {
            if(bits[i] == len) {
                res |= (1 << i);
            }
        }
        return res;
    }
    
    long long atmost(vector<int>&nums, int k) {
        int n = nums.size();
        vector<int> bits(32, 0);
        long long res = 0;
        int i = 0;
        for(int j = 0; j < nums.size(); ++j) {
            for(int x = 0; x < 32; ++x) {
                if((nums[j] & (1 << x)) != 0) {
                    bits[x]++;
                }
            }
    
            while(i <= j && calc(bits, j - i + 1) <= k) {
                res += (n - j);
                for(int x = 0; x < 32; ++x) {
                    if((nums[i] & (1 << x)) != 0) {
                        bits[x]--;
                    }
                }
                i++;
            }
        }
        return res;
    }
    
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};