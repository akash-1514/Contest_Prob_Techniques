class Solution {
public:
    long long minimumCost(int m, int n, vector<int>&X, vector<int>& Y) {
        long long hsum = 0, vsum = 0;
        for(int ele : X) {
            hsum += ele;
        }
        
        for(int ele : Y) {
            vsum += ele;
        }
        
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        
        long long ans = 0;
        
        int i = X.size() - 1, j = Y.size() - 1;
        while(i >= 0 && j >= 0) {
            if(X[i] > Y[j]) {
                ans += (X[i] + vsum);
                hsum -= X[i--];
            } else {
                ans += (Y[j] + hsum);
                vsum -= Y[j--];
            }
        }
        
        while(i >= 0) {
            ans += X[i--];
        }
    
        while(j >= 0) {
            ans += Y[j--];
        }
        
        return ans;
    }
};