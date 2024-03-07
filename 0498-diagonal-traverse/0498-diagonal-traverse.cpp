class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int>ans;
        bool fl = true;
        for(int i = 0; i < n; ++i) {
            int r = i, c = 0;
            vector<int> d;
            while(r >= 0 && c < m) {
                d.push_back(matrix[r][c]);
                r--, c++;
            }
            if(!fl) {
                reverse(d.begin(), d.end());
            }
            
            for(int ele : d) {
                ans.push_back(ele);
            }
            
            fl = !fl;
        }
        
        for(int j = 1; j < m; ++j) {
            int r = n - 1, c = j;
            vector<int>d;
            while(r >= 0 && c < m) {
                d.push_back(matrix[r][c]);
                r--, c++;
            }
            if(!fl) {
                reverse(d.begin(), d.end());
            }
            for(int ele : d) {
                ans.push_back(ele);
            }
            fl = !fl;
        }
        return ans;
    }
};