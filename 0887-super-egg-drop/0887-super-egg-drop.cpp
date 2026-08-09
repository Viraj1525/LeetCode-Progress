class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<int> mem(k+1,0);
        int moves = 0;
        while(mem[k]<n){
            moves++;
            for(int i=k; i>=1; i--){
                mem[i] = mem[i] + mem[i-1] + 1;
            }
        }
        return moves;
    }
};