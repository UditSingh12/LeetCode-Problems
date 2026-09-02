class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool hasOdd = false;

        for (int x : nums1) {
            if (x % 2 != 0) {
                hasOdd = true;
                break;
            }
        }
        return true;
    }
};