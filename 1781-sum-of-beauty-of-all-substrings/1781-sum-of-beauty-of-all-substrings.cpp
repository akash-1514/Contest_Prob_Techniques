class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            vector<int> freq(26, 0);
            multiset<int>st;
            for(int j = i; j < n; ++j) {
                if(st.find(freq[s[j] - 'a']) != st.end()) {
                    st.erase(st.find(freq[s[j] - 'a']));
                }
                freq[s[j] - 'a']++;
                st.insert(freq[s[j] - 'a']);
                ans += (*st.rbegin() - *st.begin());
            }
        }
        return ans;
    }
};