class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));

        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++)
                dp[i][j] = s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]);

        vector<int> ans(n + 1);

        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i - 1];

            for (int j = 0; j < i; j++) {
                if (i - j >= k && dp[j][i - 1])
                    ans[i] = max(ans[i], ans[j] + 1);
            }
        }

        return ans[n];
    }
};