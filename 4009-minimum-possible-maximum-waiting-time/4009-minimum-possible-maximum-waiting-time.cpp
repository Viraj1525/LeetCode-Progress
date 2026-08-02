class Solution {
public:
    int minMaxWaitingTime(vector<int>& demand, vector<int>& fuel) {

        set<pair<int,int>> st, nx;
        st.insert({fuel[0], fuel[1]});

        int n = demand.size(), k = 0;

        for (int i = 0; i < n; i++) {
            nx.clear();

            for (auto [a, b] : st) {
                if (a >= demand[i]) nx.insert({a - demand[i], b});
                if (b >= demand[i]) nx.insert({a, b - demand[i]});
            }

            if (nx.empty()) {
                k = i;
                break;
            }

            st = nx;
            k = i + 1;
        }

        if (k == 0) return -1;

        auto ok = [&](int w) {
            unordered_map<string, int> dp;

            function<int(int,int,int,int,int,int)> dfs =
            [&](int i, int a, int b, int t0, int t1, int r) {
                if (i == k) return 1;

                string s = to_string(i) + "|" + to_string(a) + "|" +
                           to_string(b) + "|" + to_string(t0) + "|" +
                           to_string(t1) + "|" + to_string(r);

                if (dp.count(s)) return dp[s];

                int d = demand[i];

                if (a >= d && t0 <= r + w) {
                    int stt = max(r, t0);
                    if (dfs(i + 1, a - d, b, stt + d, t1, stt))
                        return dp[s] = 1;
                }

                if (b >= d && t1 <= r + w) {
                    int stt = max(r, t1);
                    if (dfs(i + 1, a, b - d, t0, stt + d, stt))
                        return dp[s] = 1;
                }

                return dp[s] = 0;
            };

            return dfs(0, fuel[0], fuel[1], 0, 0, 0);
        };

        int l = 0, r = 100, ans = 100;

        while (l <= r) {
            int m = (l + r) / 2;

            if (ok(m)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return ans;
    }
};