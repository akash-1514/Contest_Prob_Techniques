class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>st;
        vector<int> lastIndex(26, 0), isOccur(26, 0);
        for(int i = 0; i < s.size(); ++i) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        for(int i = 0; i < s.size(); ++i) {
            if(isOccur[s[i] - 'a']) continue;
            while(!st.empty() && st.top() >= s[i] && lastIndex[st.top() - 'a'] >= i) {
                isOccur[st.top() - 'a'] = 0;
                st.pop();
            }
            isOccur[s[i] - 'a'] = 1;
            st.push(s[i]);
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};