class Solution {
public:
    int findPartition(vector<int>&nums, int start, int end) {
        int pivot = nums[start];
        
        int i = start, j = end;
        while(i < j) {
            while(i < end && nums[i] <= pivot) {
                i++;
            }
            
            while(j > start && nums[j] > pivot) {
                j--;
            }
            
            if(i < j) {
                swap(nums[i], nums[j]);
            }
        }
        
        swap(nums[start], nums[j]);
        return j;
    }
    
    void quickSort(vector<int>&nums, int start, int end) {
        if(start >= end) {
            return;
        }
        
        int partition = findPartition(nums, start, end);
        
        quickSort(nums, start, partition - 1);
        quickSort(nums, partition + 1, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};