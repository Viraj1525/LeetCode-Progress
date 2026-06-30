class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> m;
        int sum = 0;

        while(1){
            sum=0;
            if(n == 1) return true;
            while(n>0){
                sum += pow(n%10,2);
                n /= 10;
            }
            m[sum]++;
            if(m[sum]>1) break;
            n = sum;   
        }
        return false;
    }
};

