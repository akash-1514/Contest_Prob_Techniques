class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        vector<int>arr;
        long long sum = 0;
        for(int ele : nums) arr.push_back(ele), sum += ele;
        for(int ele : nums) arr.push_back(ele);
        
        int x = (target / sum), rem = target % sum;
        
        int sz = 1e9, i = 0, s = 0, ans = 1e9;
        for(int j = 0; j < arr.size(); ++j) {
            s += arr[j];
            while(s > rem) {
                s -= arr[i++];
            }
            if(s == rem) sz = min(sz, j - i + 1);
        }
    
        if(sz != 1e9) {
            return x * nums.size() + sz;
        }
        
        return ans == 1e9 ? -1 : ans;
    }
};