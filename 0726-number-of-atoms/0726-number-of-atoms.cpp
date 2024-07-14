class Solution {
public:
    string countOfAtoms(string s) {
        int n = s.size();
        map<string, int>mp;
        stack<pair<string, int>>st;
        for(int i = 0; i < n; ++i) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                string chem = "";
                chem += s[i];
                while(i < n && (s[i + 1] >= 'a' && s[i + 1] <= 'z')) {
                    chem += s[i + 1];
                    i++;
                }
                      
                int num = 0;
                if(s[i + 1] >= '0' && s[i + 1] <= '9') {
                    while(i < n - 1 && (s[i + 1] >= '0' && s[i + 1] <= '9')) {
                        num = num * 10 + (s[i + 1] - '0');
                        i++;
                    }
                }
                
                if(num == 0) num = 1;
            
                st.push({chem, num});
                
            } else if(s[i] == '(') {
                st.push({"(", 0});
            } else if(s[i] >= ')') {
                int num = 0;
                while(i < n - 1 && (s[i + 1] >= '0' && s[i + 1] <= '9')) {
                    num = num * 10 + (s[i + 1] - '0');
                    i++;
                }
                
                if(num == 0) num = 1;
                
                stack<pair<string, int>>st2;
                while(!st.empty() && st.top().first != "(") {
                    int x = st.top().second;
                    string chem = st.top().first;
                    st2.push({chem, x * num});
                    st.pop();
                }        
                
                
                st.pop();
                
                while(!st2.empty()) {
                    st.push(st2.top());
                    st2.pop();
                }
            }
        }
        
        while(!st.empty()) {
            mp[st.top().first] += st.top().second;
            st.pop();
        }
                    
        string ans = "";
        for(auto &it : mp) {
            ans += it.first;
            if(it.second != 1) {
                ans += to_string(it.second);
            }
        }
        return ans;
    }
};