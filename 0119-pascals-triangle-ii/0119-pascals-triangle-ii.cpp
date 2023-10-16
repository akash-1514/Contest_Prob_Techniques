class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascal(rowIndex + 1);
        for(int i = 0; i <= rowIndex; ++i) {
            pascal[i].resize(i + 1, 1);
        }
        
        for(int i = 1; i < rowIndex; ++i) {
            for(int j = 0; j < i; ++j) {
                pascal[i + 1][j + 1] = pascal[i][j] + pascal[i][j + 1];
            }
        }
        
        return pascal[rowIndex];
    }
};