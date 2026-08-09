class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[1] = 1;
        if(n>=2) dp[2] = 2;
        if(n>=3) dp[3] = 3;

        for(int i=4; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};