class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int pre = 1, suff =1;

        for(int i=0; i<n; i++){
            pre *= nums[i];
            suff *= nums[n-1-i];

            ans = max(ans,max(pre,suff));

            if(pre == 0) pre = 1;
            if(suff == 0) suff = 1;

        }
        return ans;
        
    }
};