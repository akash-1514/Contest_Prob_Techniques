class Solution {
public:
    string countOfAtoms(string s) {
        int n = s.size();
        stack<int>st;
        vector<int> prefix(n, 0);
        int prod = 1;
        string num = "";
        for(int i = n - 1; i >= 0; --i) {
            if(s[i] >= '0' && s[i] <= '9') {
                num += s[i];
            } else if(s[i] == ')') {
                if(num != "") {
                    reverse(num.begin(), num.end());
                    st.push(stoi(num));
                    prod *= stoi(num);
                    num = "";
                } else {
                    st.push(1);
                }
            } else if(s[i] == '(') {
                prod /= st.top();
                st.pop();
            } else {
                num = "";
            }
            prefix[i] = prod;
        }
        
        map<string, int>mp;
        
        for(int i = 0; i < n; ++i) {
            int start = i;
            if(s[i] >= 'A' && s[i] <= 'Z') {
                string chem = ""; chem += s[i];
                while(i < n - 1 && (s[i + 1] >= 'a' && s[i + 1] <= 'z')) {
                    chem += s[i + 1];
                    i++;
                }
                
                int num = 0;
                while(i < n - 1 && (s[i + 1] >= '0' && s[i + 1] <= '9')) {
                    num = num * 10 + (s[i + 1] - '0');
                    i++;
                }
                
                if(num != 0) {
                    mp[chem] += prefix[start] * num;
                } else {
                    mp[chem] += prefix[start];
                }
            }
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