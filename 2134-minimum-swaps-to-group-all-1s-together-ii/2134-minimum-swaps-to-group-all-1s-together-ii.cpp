class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> v;
        for(int ele : nums) v.push_back(ele);
        for(int ele : nums) v.push_back(ele);
        
        int totalOnes = 0;
        for(int ele : nums) totalOnes += (ele == 1);
        
        int ones = 0, ans = 1e9;
        for(int i = 0; i < totalOnes; ++i) {
            if(v[i] == 1) ones++;
        }
        
        ans = min(ans, totalOnes - ones);
        
        for(int i = totalOnes; i < v.size(); ++i) {
            if(i - totalOnes >= nums.size()) break;
            if(v[i] == 1) ones++;
            if(v[i - totalOnes] == 1) ones--;
            
            ans = min(ans, totalOnes - ones);
        }
        
        return ans;
    }
};