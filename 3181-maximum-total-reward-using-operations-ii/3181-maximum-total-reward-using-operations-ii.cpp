class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());
        int maxValue = rewardValues[n - 1] - 1;
        bitset<50000>curr, prev, mask;
        curr[0] = true; // reward initially = 0
        
        int maskIdx = 0;
        for(int i = 0; i < n - 1; ++i) {
            if(maskIdx < rewardValues[i]) {
                while(maskIdx < rewardValues[i]) {
                    mask[maskIdx++] = true;
                }
                curr |= ((curr & mask) << rewardValues[i]);
            }
        }
    
        while(!curr[maxValue]) {
            maxValue--;
        }
        
        return maxValue + rewardValues[n - 1];
    }
};