class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> freq(32, 0);
        int mx = 0;
        for(int ele : candidates) {
            for(int i = 0; i < 32; ++i) {
                if((ele & (1 << i)) != 0) {
                    freq[i]++;
                    mx = max(mx, freq[i]);
                }
            }
        }
        return mx;
    }
}; 