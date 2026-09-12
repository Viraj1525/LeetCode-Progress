struct State {
    long long score = 0;
    vector<int> ids;
};

bool better(const State& a, const State& b) {
    if (a.score != b.score)
        return a.score > b.score;

    return a.ids < b.ids;
}

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++)
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};

        sort(a.begin(), a.end(), [](auto& x, auto& y) {
            if (x[1] != y[1])
                return x[1] < y[1];
            if (x[0] != y[0])
                return x[0] < y[0];
            return x[3] < y[3];
        });

        vector<long long> end(n);
        for (int i = 0; i < n; i++)
            end[i] = a[i][1];

        vector<int> prev(n);
        for (int i = 0; i < n; i++)
            prev[i] =
                lower_bound(end.begin(), end.end(), a[i][0]) - end.begin();

        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= 4; k++) {
                State take = dp[prev[i - 1]][k - 1];

                take.score += a[i - 1][2];
                take.ids.push_back(a[i - 1][3]);
                sort(take.ids.begin(), take.ids.end());

                dp[i][k] = better(take, dp[i - 1][k]) ? take : dp[i - 1][k];
            }
        }

        return dp[n][4].ids;
    }
};