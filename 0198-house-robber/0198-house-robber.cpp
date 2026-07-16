class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = 0, curr = 0;
        for(int i=0; i<n; i++){
            int temp = prev;
            prev = curr;
            curr = max(curr, temp + nums[i]);
        }
        return curr;
    }
};