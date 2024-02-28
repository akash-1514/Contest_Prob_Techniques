class Solution {
public:
    int dfs(vector<int> graph[], int src, vector<int>&vis) {
        vis[src] = 1;
        int cnt = 1;
        for(auto &c : graph[src]) {
            if(!vis[c]) {
                cnt += dfs(graph, c, vis);
            }
        }
        return cnt;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        unordered_map<int, vector<int>>mp;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int ele = nums[i];
            for(int j = 2; j * j <= ele; ++j) {
                if(ele % j == 0) {
                    mp[j].push_back(i);
                    while(ele % j == 0) {
                        ele /= j;
                    }
                }
            }
            if(ele != 1) {
                mp[ele].push_back(i);
            }
        }
        
        vector<int> graph[n];
        
        for(auto &it : mp) {
            vector<int> vec = it.second;
            for(int i = 0; i < vec.size() - 1; ++i) {
                graph[vec[i]].push_back(vec[i + 1]);
                graph[vec[i + 1]].push_back(vec[i]);
            }
        }
    
        vector<int> vis(n, 0);
        int res = dfs(graph, 0, vis);
        return res == n;
    }
};