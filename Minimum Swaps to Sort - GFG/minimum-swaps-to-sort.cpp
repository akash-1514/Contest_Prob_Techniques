//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums) {
	    vector<pair<int, int>>vec;
	    for(int i = 0; i < nums.size(); ++i) {
	        vec.push_back({nums[i], i});
	    }
	    sort(vec.begin(), vec.end());
	    unordered_map<int, int>mp;
	    for(int i = 0; i < nums.size(); ++i) {
	        mp[i] = vec[i].second;
	    }
	    
	    vector<int> vis(nums.size(), 0);
	    
	    int ans = 0;
	    for(int i = 0; i < nums.size(); ++i) {
	        if(vis[i]) continue;
	        int idx = i, cnt = 0;
	        while(!vis[idx]) {
	            vis[idx] = 1;
	            cnt++;
	            idx = mp[idx];
	        }
	        ans += (cnt - 1);
	    }
	    
	    return ans;
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
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends