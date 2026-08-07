class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            int temp = nums[i] + nums[n-i-1];
            ans = max(ans,temp);
        }
        return ans;
    }
};