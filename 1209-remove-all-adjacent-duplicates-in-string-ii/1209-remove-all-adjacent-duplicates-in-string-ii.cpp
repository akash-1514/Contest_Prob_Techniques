class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>>st;
        for(int i = 0; i < s.size();) {
            int cnt = 0;
            char ch = s[i];
            while(i < s.size() && s[i] == ch) {
                cnt++, i++;
            }
            if(!st.empty()) {
                if(st.top().first == ch) {
                    int c = st.top().second;
                    c += cnt;
                    st.pop();
                    if(c % k != 0) {
                        st.push({ch, c % k});
                    }
                } else {
                    if(cnt % k != 0) {
                        st.push({ch, cnt % k});
                    }
                }
            } else {
                if(cnt % k != 0) {
                    st.push({ch, cnt % k});
                }
            }
        }
        
        string ans = "";
        while(!st.empty()) {
            for(int i = 0; i < st.top().second; ++i) {
                ans += st.top().first;
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};