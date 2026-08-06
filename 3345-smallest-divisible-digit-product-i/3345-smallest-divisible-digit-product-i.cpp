class Solution {
public:

    int helper(int n){
        int product = 1;
        while(n>0){
            product *= n%10;
            n /=10;
        }
        return product;
    }

    int smallestNumber(int n, int t) {
        int ans = n;
        int product = helper(n);
        while(product%t != 0){
            n++;
            product = helper(n);
            ans = n;
        }
        return ans;
        
    }
};