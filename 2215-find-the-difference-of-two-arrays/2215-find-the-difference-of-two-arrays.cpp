class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<set<int>> ans(2);

        for (int i = 0; i < n1; i++) {
            int temp = nums1[i]; bool present = false;
            for (int j = 0; j < n2; j++) if (nums2[j] == temp) present = true;
            if (present == false) ans[0].insert(nums1[i]);
        }

        for (int i = 0; i < n2; i++) {
            int temp = nums2[i]; bool present = false;
            for (int j = 0; j < n1; j++) if (nums1[j] == temp) present = true;
            if (present == false) ans[1].insert(nums2[i]);
        }

        vector<vector<int>> finalans(2);

        for (auto val : ans[0]) finalans[0].push_back(val);
        for (auto val : ans[1]) finalans[1].push_back(val);

        return finalans;
    }
};