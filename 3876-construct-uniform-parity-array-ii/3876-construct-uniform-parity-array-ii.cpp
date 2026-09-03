class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = nums1[0];

        // Find the smallest element
        for (int i = 1; i < nums1.size(); i++) {
            if (nums1[i] < mn) {
                mn = nums1[i];
            }
        }

        // If smallest element is odd -> we can make all numbers odd
        if (mn % 2 == 1) {
            return true;
        }
        // Smallest is even, so all numbers -> must already be even
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % 2 == 1) {
                return false;
            }
        }

        return true;
    }
};