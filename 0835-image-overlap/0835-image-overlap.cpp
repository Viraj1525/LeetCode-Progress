class Solution {
public:
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size(), ans = 0;
        
        for (int dx = -n + 1; dx < n; dx++)
            for (int dy = -n + 1; dy < n; dy++) {
                int cnt = 0;
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        if (i + dx >= 0 && i + dx < n &&
                            j + dy >= 0 && j + dy < n &&
                            a[i][j] && b[i + dx][j + dy])
                            cnt++;
                ans = max(ans, cnt);
            }
        
        return ans;
    }
};