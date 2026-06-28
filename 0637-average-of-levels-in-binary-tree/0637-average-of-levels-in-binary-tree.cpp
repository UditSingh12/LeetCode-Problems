/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<long long> sum;
    vector<int> count;

    void dfs(TreeNode* root, int level) {
        if (root == NULL)
            return;

        if (level == sum.size()) {
            sum.push_back(0);
            count.push_back(0);
        }

        sum[level] += root->val;
        count[level]++;

        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }


    vector<double> averageOfLevels(TreeNode* root) {
        
        dfs(root, 0);

        vector<double> ans;

        for (int i = 0; i < sum.size(); i++) {
            ans.push_back((double)sum[i] / count[i]);
        }

        return ans;
    }
};