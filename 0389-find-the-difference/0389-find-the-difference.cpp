class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;
        for(char ch : s) ans ^= (ch - 'a');
        for(char ch : t) ans ^= (ch - 'a');
        return ans + 'a';  
    }
};