class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        cout << nums.size() << "\n";
        int totSum = 0;
        for(int ele : nums) totSum += ele;
        int remSum = totSum - x;
        if(remSum < 0) return -1;
        long long i = 0, sum = 0, mx = -1e9;
        for(int j = 0; j < nums.size(); ++j) {
            sum += nums[j];
            while(sum > remSum) {
                sum -= nums[i++];
            }
            if(sum == remSum) {
                mx = max(mx, j - i + 1);
            }
        }
        return (mx == -1e9) ? -1 : (nums.size() - mx);
    }
};