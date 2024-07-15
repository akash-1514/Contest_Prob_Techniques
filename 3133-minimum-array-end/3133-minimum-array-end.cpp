class Solution {
public:
    long long minEnd(int n, int x) {
        long long res = x;
        int idx = 0;
        for(int j = 0; j < 64; ++j) {
            if((res & (1ll << j)) == 0) {
                if(((n - 1) & (1ll << idx)) != 0) {
                    res |= (1ll << j);
                }
                idx++;
            }
        }
        return res;
    }
};