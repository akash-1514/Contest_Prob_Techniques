class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int>mp;
        for(char ch : s) {
            mp[ch]++;
        }
        
        priority_queue<pair<int, char>>pq;
        
        for(auto &it : mp) {
            pq.push({it.second, it.first});
        }
        
        string ans = "";
        while(!pq.empty()) {
            pair<int, char>tp = pq.top(); pq.pop();
            ans.push_back(tp.second);
            if(!pq.empty()) {
                pair<int, char>tp2 = pq.top(); pq.pop();
                ans.push_back(tp2.second);
                if(tp2.first - 1 > 0) {
                    pq.push({tp2.first - 1, tp2.second});
                }
            }
            
            if(tp.first - 1 > 0) {
                pq.push({tp.first - 1, tp.second});
            }
        }
        
        for(int i = 0; i < ans.size() - 1; ++i) {
            if(ans[i] == ans[i + 1]) return "";
        }
        
        return ans;
    }
};