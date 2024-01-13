class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq1(26, 0);
        
        for(char ch : s) freq1[ch - 'a']++;
        for(char ch : t) freq1[ch - 'a'] = max(0, --freq1[ch - 'a']);
        
        int op = 0;
        for(int i = 0; i < 26; ++i) {
            op += freq1[i];
        }
        return op;
    }
};