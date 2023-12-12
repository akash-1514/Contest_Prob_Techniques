class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>>pq;
        
        vector<int> vec;
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += mat[i][0];
            vec.push_back(0);
        }
        
        pq.push({sum, vec});
        
        set<vector<int>>vis;
        
        while(!pq.empty() && k--) {
            auto tp = pq.top();
            pq.pop();
            
            int s = tp.first;
            vector<int> v = tp.second;
        
            if(k == 0) {
                return s;
            }
            
            for(int i = 0; i < v.size(); ++i) {
                if(v[i] + 1 < m) {
                    v[i]++;
                    if(vis.find(v) == vis.end()) {
                        int newSum = (s + (mat[i][v[i]] - mat[i][v[i] - 1]));
                        pq.push({newSum, v});
                        vis.insert(v);
                    }
                    v[i]--;
                }
            }
        }
        return -1;
    }
};