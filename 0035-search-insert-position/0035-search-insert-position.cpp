class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(target > nums[n-1]) return n;
        if(target < nums[0]) return 0;

        int start = 0;
        int end = n-1;

        while(end > start) {
            if(end == start + 1) {
                if(nums[start] == target) return start;
                else return end;
            }

            int mid = start + (end-start)/2;
            if (nums[mid] == target){
                return mid;
            }
            if(target > nums[mid]){
                start = mid;
            } else {
                end = mid;
            }
            
        }
        return 0;

        
    }
};