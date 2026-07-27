class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstMax=0;
        int secondMax=0;

        for (int x : nums) {
            if (x > firstMax) {
                secondMax = firstMax;
                firstMax = x;
            } else if (x > secondMax) {
                secondMax = x;
            }
        }

        return (firstMax - 1) * (secondMax - 1);
    }
};