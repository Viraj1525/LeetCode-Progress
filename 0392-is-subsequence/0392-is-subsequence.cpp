class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        int i = 0;
        int j = 0;

        if(n==0) return true;

        while(i<n && j<m){
            if(i==n-1 && s[i] == t[j]){
                return true;
            }
            if(s[i] == t[j]){
                i++; j++;
            } else {
                j++;
            }
        }
        return false;
    }
};