class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int maxCandies = 0;

         // Find maximum
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] > maxCandies) {
                maxCandies = candies[i];
            }
        }

        

        // Checking for each kid
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= maxCandies)
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};