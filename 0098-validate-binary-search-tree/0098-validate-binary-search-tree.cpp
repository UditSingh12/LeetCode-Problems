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

    bool validate(TreeNode* root,long min,long max){
        if(root==NULL){
            return true;
        }
        if(root->val<=min){
            return false;
        }
        if(root->val>=max){
            return false;
        }
        //Left Sub-Tree from Min Range to root
        return validate(root->left,min,root->val)
        &&
        validate(root->right,root->val,max);     
        //Right Sub-Tree from root to Max
    }

    bool isValidBST(TreeNode* root) {
        
        // Defining a range Initially From -MIN to +MAX

        return validate(root,LONG_MIN,LONG_MAX);
    }
};