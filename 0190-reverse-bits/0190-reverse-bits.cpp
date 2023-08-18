class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int ans = 0;
        vector<int>vec;
        for(int i = 0; i < 32; ++i) {
            if((n & (1ll << i)) != 0) {
                vec.push_back(1);
            } else {
                vec.push_back(0);
            }
        }
        
        long long pow = 1;
        for(int i = vec.size() - 1; i >= 0; --i) {
            ans += (vec[i] * 1ll * pow);
            pow *= 2;
        }
        return ans;
    }
};