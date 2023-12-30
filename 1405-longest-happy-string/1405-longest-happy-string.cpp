class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>>pq;
        if(a != 0) pq.push({a, 'a'});
        if(b != 0) pq.push({b, 'b'});
        if(c != 0) pq.push({c, 'c'});
        
        string ans = "";
        while(pq.size() > 1) {
            pair<int, char> tp1 = pq.top(); pq.pop();
            if(tp1.first >= 2) {
                ans += tp1.second;
                ans += tp1.second;
                tp1.first -= 2;
            } else {
                ans += tp1.second;
                tp1.first--;
            }
            
            pair<int, char> tp2 = pq.top(); pq.pop();
            
            if(tp2.first >= 2 && tp2.first >= tp1.first) {
                ans += tp2.second;
                ans += tp2.second;
                tp2.first -= 2;
            } else {
                ans += tp2.second;
                tp2.first--;
            }
            
            if(tp1.first > 0) pq.push(tp1);
            if(tp2.first > 0) pq.push(tp2);
        }
        
        if(!pq.empty()) {
            if(pq.top().first >= 2) {
                ans += pq.top().second;
                ans += pq.top().second;
            } else {
                ans += pq.top().second;
            }
        }
        
        return ans;
    }
};