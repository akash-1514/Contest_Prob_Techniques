class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        map<int, vector<int>>mp;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                mp[i + j].push_back(matrix[i][j]);
            }
        }
        
        vector<int>ans;
        bool fl = true;
        for(auto &it : mp) {
            vector<int> vec = it.second;
            if(fl) {
                reverse(vec.begin(), vec.end());
            }
            for(int ele : vec) {
                ans.push_back(ele);
            }
            fl = !fl;
        }
        return ans;
    }
};