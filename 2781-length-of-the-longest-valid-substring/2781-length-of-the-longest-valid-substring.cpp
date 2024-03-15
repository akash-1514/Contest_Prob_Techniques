class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_map<string, int>mp;
        unordered_map<int, int>mark;
        for(auto &str : forbidden) mp[str]++;
        int n = word.size();
        for(int i = 0; i < n; ++i) {
            string sub = "";
            for(int j = i; j < min(n, i + 10); ++j) {
                sub += word[j];
                if(mp.find(sub) != mp.end()) {
                    mark[j] = max(mark[j], i);
                }
            }
        }
        
        int i = 0, ans = 0;
        for(int j = 0; j < n; ++j) {
            
            if(mark.find(j) != mark.end()) {
                if(mark[j] >= i) {
                    i = mark[j] + 1;
                }
            }
            
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};