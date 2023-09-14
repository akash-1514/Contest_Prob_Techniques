//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[101][101];
    int helper(int arr[], int n, int i, int j) {
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int minCost = 1e9;
        for(int k = i; k < j; ++k) {
            int cost = (arr[i - 1] * arr[k] * arr[j]) + helper(arr, n, i, k) + helper(arr, n, k + 1, j);
            minCost = min(minCost, cost);
        }
        return dp[i][j] = minCost;
    }
    int matrixMultiplication(int N, int arr[]) {
        memset(dp, -1, sizeof(dp));
        return helper(arr, N, 1, N - 1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends