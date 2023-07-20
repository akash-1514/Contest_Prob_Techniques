//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    vector<vector<int>>dp;
    int helper(int wt[], int val[], int idx, int W, int n) {
        if(idx >= n) return 0;
        if(dp[idx][W] != -1) return dp[idx][W];
        int pick = 0;
        if(wt[idx] <= W) {
            pick = val[idx] + helper(wt, val, idx +1 , W - wt[idx], n);
        }
        int notPick = helper(wt, val, idx + 1, W, n);
        return dp[idx][W] = max(pick, notPick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        dp.resize(n, vector<int>(W + 1, -1));
        return helper(wt, val, 0, W, n);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends