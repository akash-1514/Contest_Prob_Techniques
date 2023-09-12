class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(char ch : s) {
            freq[ch - 'a']++;
        }
        
        sort(freq.begin(), freq.end());
        
        int ans = 0, prev = freq[25];
        for(int i = 24; i >= 0; --i) {
            if(freq[i] == 0) break;
            if(freq[i] >= prev) {
                ans += abs(freq[i] - prev) + 1;
                if(prev - 1 > 0) {
                    prev--;
                } 
            } else {
                prev = freq[i];
            }
        }
        return ans;
    }
};