class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> vec1(26, 0), vis(26, 0);
        for(int i = 0; i < s.size(); ++i) {
            vec1[s[i] - 'a'] = i;
        }
        stack<char>st;
        for(int i = 0; i < s.size(); ++i) {
            if(vis[s[i] - 'a']) continue;
            while(!st.empty() && vec1[st.top() - 'a'] >= i && st.top() > s[i]) {
                vis[st.top() - 'a'] = 0;
                st.pop();
            }
            vis[s[i] - 'a'] = 1;
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