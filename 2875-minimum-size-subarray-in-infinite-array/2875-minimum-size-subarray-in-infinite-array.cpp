class Solution {
public:
    int minSizeSubarray(vector<int>& arr, int target) {
        vector<int>nums;
        for(int ele : arr) {
            nums.push_back(ele);
        }
        for(int ele : arr) {
            nums.push_back(ele);
        }
        long long sum = 0;
        for(int ele : arr) sum += ele;
        
        int sz = (target / sum) * arr.size();
        int rem = target % sum;
        
        int mn = 1e9, s = 0, i = 0;
        for(int j = 0; j < nums.size(); ++j) {
            s += nums[j];
            while(s > rem) {
                s -= nums[i++];
            }
            if(s == rem) {
                mn = min(mn, j - i + 1);
            }
        }
        
        int sz2 = 1e9;
        i = 0, s = 0;
        for(int j = 0; j < nums.size(); ++j) {
            s += nums[j];
            while(s > target) {
                s -= nums[i++];
            }
            if(s == target) {
                sz2 = min(sz2, j - i + 1);
            }
        }
        
        int ans = 1e9;
        if(mn != 1e9) {
            ans = min(ans, sz + mn);
        }
        
        ans = min(ans, sz2);
        return ans == 1e9 ? -1 : ans;
    }
};