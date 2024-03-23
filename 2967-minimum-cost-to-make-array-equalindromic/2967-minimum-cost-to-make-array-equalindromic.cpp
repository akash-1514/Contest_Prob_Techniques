class Solution {
public:
    bool check(int x) {
        int temp = x;
        int rev = 0;
        while(x != 0) {
            int r = x % 10;
            rev = rev * 10 + r;
            x /= 10;
        }
        return rev == temp;
    }
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ele = nums[nums.size() / 2];
        
        int left = ele, right = ele;
        while(left > 0) {
            if(check(left)) {
                break;
            }
            left--;
        }
        
        while(1) {
            if(check(right)) {
                break;
            }
            right++;
        }
        
        long long cost1 = 0, cost2 = 0;
        for(int i = 0; i < nums.size(); ++i) {
            cost1 += abs(nums[i] - left);
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            cost2 += abs(nums[i] - right);
        }
        
        return min(cost1, cost2);
    }
};