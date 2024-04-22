class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<int, string>>q;
        unordered_map<string, int>mp;
        for(auto &str : deadends) {
            mp[str]++;
        }
        
        if(mp["0000"] > 0)  return -1;
        
        q.push({0, "0000"});
        unordered_set<string>vis;
        vis.insert("0000");
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            int steps = front.first;
            string curr = front.second;
            
            if(curr == target) return steps;
            
            for(int i = 0; i < 4; ++i) {
                int x = curr[i] - '0', x1 = x;
                x = (x + 1) % 10;
                curr[i] = x + '0';
                if(mp[curr] == 0) {
                    if(!vis.count(curr)) {
                        vis.insert(curr);
                        q.push({steps + 1, curr});
                    }
                }
                
                int x2 = x1;
                x2 = (x2 - 1 + 10) % 10;
                
                curr[i] = x2 + '0';
                
                if(mp[curr] == 0) {
                    if(!vis.count(curr)) {
                        vis.insert(curr);
                        q.push({steps + 1, curr});
                    }
                }
                
                curr[i] = x1 + '0';   
            }
        }
        return -1;
    }
};