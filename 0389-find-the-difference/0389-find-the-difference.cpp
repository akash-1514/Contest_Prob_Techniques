class Solution {
public:
    char findTheDifference(string s, string t) {
        int num = 0;
        for(char ch : s) num ^= (1 << (ch - 'a'));
        for(char ch : t) num ^= (1 << (ch - 'a'));
        
        char ans;
        for(int i = 0; i < 26; ++i) {
            if(num & (1 << i)) {
                ans = i + 'a';
                break;
            }
        }
        
        return ans;
    }
};