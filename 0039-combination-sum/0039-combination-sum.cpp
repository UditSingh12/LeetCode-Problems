class Solution {
public:
    void helper(vector<int>& a, int n, int idx, vector<int>& diary,
            int sum, vector<vector<int>>& res, int target) {
        
        if (sum == target) {
            res.push_back(diary);
            return;
        }

        if (idx == n || sum > target) {
            return;
        }

        // Choice 1: take current element
        diary.push_back(a[idx]);
        helper(a, n, idx, diary, sum + a[idx], res, target);
        diary.pop_back();

        // Choice 2: skip current element
        helper(a, n, idx + 1, diary, sum, res, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> diary;

        helper(candidates, candidates.size(), 0, diary, 0, res, target);

        return res;
    }
};