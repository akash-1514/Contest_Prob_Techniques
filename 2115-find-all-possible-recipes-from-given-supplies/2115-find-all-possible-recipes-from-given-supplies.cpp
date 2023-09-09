class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string, int>recipe_map;
        int idx = 0;
        for(auto &str : recipes) {
            recipe_map[str] = idx++;
        }
        unordered_map<string, int>supp;
        for(auto &str : supplies) supp[str]++;
        vector<int> graph[n];
        vector<int> indegree(n, 0);
        unordered_set<int>st;
        for(int i = 0; i < n; ++i) {
            bool fl = true;
            for(int j = 0; j < ingredients[i].size(); ++j) {
                if(recipe_map.find(ingredients[i][j]) != recipe_map.end()) {
                    graph[recipe_map[ingredients[i][j]]].push_back(i);
                    indegree[i]++;
                } else if(supp[ingredients[i][j]] == 0) {
                    fl = false;
                }
            }
            if(!fl) {
                st.insert(i);
            }
        }
        
        vector<string>ans;
        queue<int>q;
        for(int i = 0; i < n; ++i) {
            if(st.count(i)) continue;
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            
            ans.push_back(recipes[front]);
            
            for(auto &adj : graph[front]) {
                if(--indegree[adj] == 0) q.push(adj);
            }
        }
        
        return ans;
    }
};