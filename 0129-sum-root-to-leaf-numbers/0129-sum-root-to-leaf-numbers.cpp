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
    int dfs(TreeNode* root, int currentNumber) {
        if (root == NULL) {
            return 0;
        }

        currentNumber = currentNumber * 10 + root->val;

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            return currentNumber;
        }

        int leftSum = dfs(root->left, currentNumber);
        int rightSum = dfs(root->right, currentNumber);

        return leftSum + rightSum;
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};