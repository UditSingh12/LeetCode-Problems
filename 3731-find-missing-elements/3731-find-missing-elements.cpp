class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;

        // Find minimum and maximum
        for (int x : nums) {
            if (x < mn)
                mn = x;
            if (x > mx)
                mx = x;
        }
        unordered_set<int> st;
        for (int x : nums) {
            st.insert(x);
        }

        vector<int> ans;

        // Check every number in the range
        for (int i = mn; i <= mx; i++) {
            if (st.find(i) == st.end()) { // If the number is not in nums we can push into ans
                ans.push_back(i);
            }
        }

        return ans;
    }
};