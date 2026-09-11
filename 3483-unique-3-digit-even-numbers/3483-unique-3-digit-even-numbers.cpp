class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_map<int,int> m;

        for(auto val : digits) m[val]++;

        int ans=0;
        for(int i=100; i<1000; i++){
            int hundreds = (i - i%100)/100; int tens = (i%100 - i%10)/10; int ones = i%10;

            if(ones%2) continue;
            m[hundreds]--; m[tens]--; m[ones]--;
            if(m[hundreds]>=0 && m[tens]>=0 && m[ones]>=0) ans++;
            m[hundreds]++; m[tens]++; m[ones]++;
        }
        return ans;
    }
};