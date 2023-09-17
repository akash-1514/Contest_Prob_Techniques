class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        vector<int> vec;
        for(int i = 1; i <= nums.size(); ++i) {
            int x = sqrt(i);
            if(x * x == i) {
                vec.push_back(i);
            }
        }
        long long mx = 0;
        for(int i = 1; i <= nums.size(); ++i) {
            long long sum = 0;
            for(int j = 0; j < vec.size(); ++j) {
                if(vec[j] * i > nums.size()) break;
                sum += nums[vec[j] * i - 1];
            }
            mx = max(mx, sum);
        }
        return mx;
    }
};