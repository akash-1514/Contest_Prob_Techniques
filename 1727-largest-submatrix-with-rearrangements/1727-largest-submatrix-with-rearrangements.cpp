class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        for(int i = 0; i < m; ++i) {
            int sum = 0;
            for(int j = 0; j < n; ++j) {
                if(arr[j][i] == 1) sum++;
                else sum = 0;
                arr[j][i] = sum; 
            }
        }
        
        int mx = 0;
        
        for(int i = 0; i < n; ++i) {
            vector<int>vec;
            for(int j = 0; j < m; ++j) {
                vec.push_back(arr[i][j]);
            }
            sort(vec.begin(), vec.end());
            for(int i = 0; i < vec.size(); ++i) {
                mx = max(mx, vec[i] * ((int)vec.size() - i));
            }
        }
        
        return mx;
    }
};