class cmp {
    public:
    bool operator() (pair<char, int>&p1, pair<char, int>&p2) {
        if(p1.first == p2.first) {
            return p1.second < p2.second;
        }
        return p1.first > p2.first;
    }
};
class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
        unordered_set<int> st;
        int idx = 0;
        for(char ch : s) {
            if(ch == '*') {
                if(!pq.empty()) {
                    st.insert(pq.top().second);
                    pq.pop();
                } 
            } else {
                pq.push({ch, idx});
            }
            idx++;
        }
        
        string ans = "";
        for(int i = 0; i < n; ++i) {
            if(st.count(i) || s[i] == '*') continue;
            ans += s[i];
        }
        return ans;
    }
};