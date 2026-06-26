class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(auto val: nums){
            s.insert(val);

            if(s.size() > 3){
                s.erase(s.begin());
            }
        }
        return (s.size() < 3)? *s.rbegin() : *s.begin();
        
    }
};