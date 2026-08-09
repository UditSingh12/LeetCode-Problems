class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int ans = 0;

        for (int x : nums) {
            int need = k - x;

            if (freq[need] > 0) {
                freq[need]--;
                ans++;
            } else {
                freq[x]++;
            }
        }

        return ans;
    }
};