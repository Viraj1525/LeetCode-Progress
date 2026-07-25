class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        int mx = 0;
        int idx = 0;
        for(int i=0; i<s.length(); i++){
            if(int(s[i]-'0') > mx){
                idx = i;
            }
            mx = max(mx,int(s[i] - '0'));
        }
        int smx = 0;
        for(int i=0; i<s.length(); i++){
            if(i != idx){
                smx = max(smx,int(s[i]-'0'));
            }
        }

        return mx * smx;


        
    }
};