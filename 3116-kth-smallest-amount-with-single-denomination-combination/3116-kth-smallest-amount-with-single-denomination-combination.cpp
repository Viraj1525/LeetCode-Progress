class Solution {
public:
    
    long long gcd(long long a, long long b){
        return b ? gcd(b, a%b) : a;
    }

    long long lcm(long long a, long long b){
        return a / gcd(a,b) * b;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto count = [&](long long x) {
            long long ans = 0;

            for (int j = 1; j < (1 << n); j++){
                long long L = 1;
                int bits = 0;

                for(int i=0; i< n; i++){
                    if (j & (1 << i)) {
                        L = lcm(L, coins[i]);
                        bits++;
                        if (L > x) break;
                    }
                }

                if (L > x) continue;

                if (bits & 1) ans += x / L;
                else ans -= x / L;
            }

            return ans;
        };
        
        long long lo = 1, hi = 1LL * *min_element(coins.begin(), coins.end()) * k;

        while (lo < hi) {
            long long mid = (lo + hi) / 2;

            if (count(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;


        
    }
};