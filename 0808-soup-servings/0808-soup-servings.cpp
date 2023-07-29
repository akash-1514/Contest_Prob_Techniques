class Solution {
public:
    vector<vector<double>>dp;
    double helper(int a, int b) {
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1.0;
        if(b <= 0) return 0.0;
        
        if(dp[a][b] != -1.0) return dp[a][b];
        
        vector<vector<double>> vec = {{100.0, 0.0}, {75.0, 25.0}, {50.0, 50.0}, {25.0, 75.0}};
        
        double prob = 0.0;
        for(int i = 0; i < 4; ++i) {
            prob += helper(a - vec[i][0], b - vec[i][1]);
        }
        return dp[a][b] = prob * 0.25;
    }
    double soupServings(int n) {
        if(n >= 5000) return 1;
        dp.resize(n + 1, vector<double>(n + 1, -1.0));
        return helper(n, n);
    }
};