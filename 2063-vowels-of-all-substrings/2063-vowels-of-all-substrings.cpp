class Solution {
public:
    long long countVowels(string word) {
        long long ans = 0;
        unordered_set<char>st = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < word.size(); ++i) {
            if(st.count(word[i])) {
                ans += ((i + 1) + (i + 1) * 1ll * (word.size() - i - 1));
            }
        }
        return ans;
    }
};