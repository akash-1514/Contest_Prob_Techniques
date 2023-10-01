class Solution {
public:
    void reverse(string &w) {
        int i = 0, j = w.size() - 1;
        while(i < j) {
            swap(w[i], w[j]);
            i++, j--;
        }
    }
    string reverseWords(string s) {
        int n = s.size();
        vector<string>words;
        for(int i = 0; i < n; ++i) {
            string word = "";
            while(i < n && s[i] != ' ') {
                word += s[i++];
            }
            words.push_back(word);
        }
        
        string ans = "";
        for(int i = 0; i < words.size(); ++i) {
            reverse(words[i]);
            if(i == words.size() - 1) {
                ans += words[i];
            } else {
                ans += (words[i] + " ");
            }
        }
        return ans;
    }
};