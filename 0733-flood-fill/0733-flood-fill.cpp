class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    void dfs(vector<vector<int>>&image, int x, int y, int orgColor, int newColor) {
        image[x][y] = newColor;
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < image.size() && ny < image[0].size() && image[nx][ny] == orgColor) {
                dfs(image, nx, ny, orgColor, newColor);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orgColor = image[sr][sc];
        if(orgColor == color) return image;
        dfs(image, sr, sc, orgColor, color);
        return image;
    }
};