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
    int checkHeight(TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        int lh = checkHeight(root->left); //Recursively check for left Height
        if (lh == -1){
            return -1;
        }
        int rh = checkHeight(root->right);  //Recursively check for Right Height
        if (rh == -1){
            return -1;
        }
        if (abs(lh - rh) > 1){
            return -1;
        }
        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        //Only -1 Difference height will be Non Balanced Tree 
        return checkHeight(root) != -1;
        
    }
};