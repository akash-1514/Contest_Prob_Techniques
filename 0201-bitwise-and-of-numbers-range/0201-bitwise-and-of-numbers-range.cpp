class Solution {
public:
    vector<int> setBitsRange(int x) {
        vector<int> bits(32, 0);
        while(x) {
            if(x == 1) {
                bits[0]++;
                break;
            } else if(x == 2) {
                bits[0]++;
                bits[1]++;
                break;
            } else {
                long long maxSetBit = log2(x);
                long long maxValue = (1ll << maxSetBit);
                bits[maxSetBit] += (x - maxValue + 1);
                for(int i = maxSetBit - 1; i >= 0; --i) {
                    bits[i] += (maxValue / 2);
                }
                
                x -= maxValue;
            }
        }
        
        return bits;
    }
    int rangeBitwiseAnd(int left, int right) {
        vector<int> rightBits(32, 0), leftBits(32, 0);
        if(left != 0) {
            leftBits = setBitsRange(left - 1);
        } 
        
        if(right != 0) {
            rightBits = setBitsRange(right);
        }
        
        int ans = 0;
        
        for(int i = 0; i < 32; ++i) {
            rightBits[i] -= leftBits[i];
            if(rightBits[i] == (1ll * right - left + 1)) {
                ans |= (1 << i);
            } 
        }
        
        return ans;
    }
};