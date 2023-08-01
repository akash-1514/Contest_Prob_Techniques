#define ppi pair<int, int>
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<vector<int>>vec;
        for(int i = 0; i < tasks.size(); ++i) {
            vec.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(vec.begin(), vec.end());
        vector<int>ans;
        priority_queue<ppi, vector<ppi>, greater<ppi>>pq;
        int i = 0;
        int time = vec[0][0];
        while(i < vec.size()) {
            while(i < vec.size() && vec[i][0] <= time) {
                pq.push({vec[i][1], vec[i][2]});
                i++;
            }
            
            if(!pq.empty()) {
                ans.push_back(pq.top().second);
                time += pq.top().first;
                pq.pop();
            } else {
                if(i < vec.size()) {
                    time = vec[i][0];
                }
            }
        }
        
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
        
    }
};