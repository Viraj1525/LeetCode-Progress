class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        int i = 0, j = n-1;
        int count = 0;
        while(i<=j){
            if(people[j]==limit){
                count++;
                j--;
            } else if(people[j]+people[i] <= limit){
                count++;
                i++;
                j--;
            } else {
                count ++;
                j--;
            }
        }
        return count;
    }
    //1 2 2 3
    //3 3 4 5
};