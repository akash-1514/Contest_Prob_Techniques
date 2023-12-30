class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>>pq;
        if(a != 0) pq.push({a, 'a'});
        if(b != 0) pq.push({b, 'b'});
        if(c != 0) pq.push({c, 'c'});
        
        string ans;
        
        while(pq.size() > 1)
        {
            pair<int, char>tp = pq.top();
            pq.pop();
            
            if(tp.first >= 2)
            {
                ans.push_back(tp.second);
                ans.push_back(tp.second);
                tp.first -= 2;
            }
            else
            {
                ans.push_back(tp.second);
                tp.first -= 1;
            }
            
            pair<int, char>stop = pq.top();
            pq.pop();
            
            if(stop.first >= 2 && stop.first >= tp.first)
            {
                ans.push_back(stop.second);
                ans.push_back(stop.second);
                stop.first -= 2;
            }
            else
            {
                ans.push_back(stop.second);
                stop.first -= 1;
            }

            if(tp.first != 0)
            {
                pq.push(tp);
            }
            
            if(stop.first != 0)
            {
                pq.push(stop);
            }
        }
        
        if(!pq.empty())
        {
            if(pq.top().first >= 2)
            {
                ans.push_back(pq.top().second);
                ans.push_back(pq.top().second);                
            }
            else
            {
                ans.push_back(pq.top().second);
            }
        }
        
        return ans;
    }
};