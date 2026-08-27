class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        vector<int> ans1, ans2;

        // nums1 elements not present in nums2
        for (int x1 : s1) {
            if (s2.find(x1) == s2.end()) {
                ans1.push_back(x1);
            }
        }

        // nums2 elements not present in nums1
        for (int x2 : s2) {
            if (s1.find(x2) == s1.end()) {
                ans2.push_back(x2);
            }
        }

        return {ans1, ans2};
    }
};