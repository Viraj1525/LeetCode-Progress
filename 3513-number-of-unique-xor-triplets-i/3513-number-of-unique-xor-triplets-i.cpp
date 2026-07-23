class Solution {
public:

    int highestOneBit(int n) {
        return 1 << (31 - __builtin_clz(n));
    }

    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n == 2) return n;
        int mx = highestOneBit(n);
        return mx << 1;
    }
};