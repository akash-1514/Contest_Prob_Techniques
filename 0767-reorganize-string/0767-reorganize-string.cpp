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
        char prev = '_';
        while(!pq.empty()) {
            pair<int, char>tp = pq.top(); pq.pop();
            if(prev == tp.second) return "";
            ans.push_back(tp.second);
            prev = tp.second;
            if(!pq.empty()) {
                pair<int, char>tp2 = pq.top(); pq.pop();
                if(prev == tp2.second) return "";
                ans.push_back(tp2.second);
                prev = tp2.second;
                if(tp2.first - 1 > 0) {
                    pq.push({tp2.first - 1, tp2.second});
                }
            }
            
            if(tp.first - 1 > 0) {
                pq.push({tp.first - 1, tp.second});
            }
        }
        
        return ans;
    }
};