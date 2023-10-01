class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        vector<int>arr;
        long long sum = 0;
        for(int ele : nums) arr.push_back(ele), sum += ele;
        for(int ele : nums) arr.push_back(ele);
        
        int x = (target / sum), rem = target % sum;
        
        int sz = 1e9, i = 0, s = 0, ans = 1e9, sz2 = 1e9, s2 = 0, i2 = 0;
        for(int j = 0; j < arr.size(); ++j) {
            s += arr[j];
            s2 += arr[j];
            while(s > rem) {
                s2 -= arr[i2++];
                s -= arr[i++];
            }
            if(s == rem) sz = min(sz, j - i + 1);
            if(s2 == target) sz2 = min(sz2, j - i2 + 1);
        }
    
        if(sz != 1e9) {
            ans = min({ans, sz2, x * (int)nums.size() + sz});
        }
        
        return ans == 1e9 ? -1 : ans;
    }
};