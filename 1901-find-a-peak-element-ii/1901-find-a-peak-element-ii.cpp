class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            int col = max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin();
            int left = (mid - 1 >= 0) ? mat[mid - 1][col] : -1;
            int right = (mid + 1 < n) ? mat[mid + 1][col] : -1;
            if(mat[mid][col] > left && mat[mid][col] > right) {
                return {mid, col};
            } else if(mat[mid][col] < left) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};