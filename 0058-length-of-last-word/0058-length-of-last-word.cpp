class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        bool flag = false;
        int ans = 0;

        for(int i = n-1; i>=0; i--){
            if (flag == false){
                if(s[i] == ' ') continue;
                else {
                    flag = true;
                    ans ++;
                }
            } else {
                if(s[i] == ' '){
                    return ans;
                } else {
                    ans ++;
                }
            }
        }
        return ans;
    }
};