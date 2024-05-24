class Solution {
public:
    map<int, map<vector<int>, int>>dp;
    bool isPossible(string &word, vector<int>&freq) {
        vector<int> f(26, 0);
        for(char ch : word) {
            f[ch - 'a']++;
        }
        
        for(int i = 0; i < 26; ++i) {
            if(f[i] > freq[i]) {
                return false;
            }
        }
        
        return true;
    }
    int helper(vector<pair<int, string>>&vec, int idx, vector<int>&freq) {
        if(idx >= vec.size()) {
            return 0;
        }
        
        if(dp.find(idx) != dp.end() && dp[idx].find(freq) != dp[idx].end()) {
            return dp[idx][freq];
        }
        
        int mx = 0;
        
        if(isPossible(vec[idx].second, freq)) {
            vector<int> f = freq;
            for(char ch : vec[idx].second) {
                f[ch - 'a']--;
            }
            mx = max(mx, vec[idx].first + helper(vec, idx + 1, f));
        }
        
        mx = max(mx, helper(vec, idx + 1, freq));
        return dp[idx][freq] = mx;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<pair<int, string>> vec;
        for(int i = 0; i < words.size(); ++i) {
            int sc = 0;
            for(char ch : words[i]) {
                sc += score[ch - 'a'];
            }
            vec.push_back({sc, words[i]});
        }
        
        vector<int> freq(26, 0);
        for(char ch : letters) {
            freq[ch - 'a']++;
        }
        
        return helper(vec, 0, freq);
    }
};