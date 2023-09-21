//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int countSmallerEqual(vector<vector<int>>&mat, int x) {
        int n = mat.size();
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            int idx = upper_bound(mat[i].begin(), mat[i].end(), x) - mat[i].begin();
            cnt += idx;
        }
        return cnt;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        int low = 1e9, high = -1e9;
        for(int i = 0; i < R; ++i) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][C - 1]);
        }
        
        int half = (R * C) / 2, ans = 0;
        while(low <= high) {
            int mid = (low + high) >> 1;
            int x = countSmallerEqual(matrix, mid);
            if(x > half) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends