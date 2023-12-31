//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size();
	    vector<int>dp(n, 1), dp2(n, 1);
	    for(int i = 1; i < n; ++i) {
	        for(int j = 0; j < i; ++j) {
	            if(nums[j] < nums[i]) {
	                dp[i] = max(dp[i], dp[j] + 1);
	            }
	        }
	    }
	    
	    for(int i = n - 2; i >= 0; --i) {
	        for(int j = i + 1; j < n; ++j) {
	            if(nums[j] < nums[i]) {
	                dp2[i] = max(dp2[i], 1 + dp2[j]);
	            }
	        }
	    }
	    
	    int mx = 0;
	    for(int i = 0; i < n; ++i) {
	        mx = max(mx, dp[i] + dp2[i] - 1);
	    }
	    return mx;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends