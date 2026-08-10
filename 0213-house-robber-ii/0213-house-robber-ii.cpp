class Solution {
public:

    int dp(vector<int> nums){
        int n = nums.size();
        
        int prev2 = nums[0];
        int prev1 = max(nums[0],nums[1]);
        int result = prev1;

        for(int i=2; i<n; i++){
            result = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = result;
        }
        return result;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);

        vector<int> result1(nums.begin()+1,nums.end());
        vector<int> result2(nums.begin(),nums.end()-1);

        return max(dp(result1), dp(result2));
    }
};