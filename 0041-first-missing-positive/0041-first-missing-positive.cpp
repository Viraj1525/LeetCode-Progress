class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i<n){
            int correctidx = 0;
            if(nums[i]>0 && nums[i]<=n){
                correctidx = nums[i] - 1;
            }
            if(nums[i]>0 && nums[i]<=n && nums[i] != nums[correctidx]){
                swap(nums[i],nums[correctidx]);
            } else {
                i++;
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        return n + 1;
        
    }
};