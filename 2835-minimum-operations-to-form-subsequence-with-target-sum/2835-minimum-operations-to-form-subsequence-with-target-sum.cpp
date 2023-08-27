class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        // long long sum = 0;
        // for(int ele : nums) sum += ele;
        // if(sum < target) return -1;
        vector<int> freq(32, 0);
        for(int ele : nums) {
            freq[log2(ele)]++;
        }
        
        int op = 0;
        for(int i = 0; i < 31; ++i) {
            if(target & (1 << i)) {
                if(freq[i] > 0) {
                    freq[i]--;
                } else {
                    int j = i;
                    while(j < 31) {
                        if(freq[j] > 0) {
                            break;
                        }
                        j++;
                    }
                    
                    if(j == 31) return -1;
                    freq[j]--;
                    
                    op += (j - i);
                    
                    while(j > i) {
                        freq[--j]++;
                    }
                }
            }
            
            freq[i + 1] += freq[i] / 2;
        }
        
        return op;
    }
};