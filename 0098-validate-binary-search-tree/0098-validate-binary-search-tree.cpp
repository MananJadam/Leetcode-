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

    bool helper(TreeNode* root, TreeNode*Min,TreeNode* Max){
        if(root==NULL) return true;

        if(Min!=NULL&&root->val<=Min->val){
            return false;
        }
        if(Max!=NULL&&root->val>=Max->val){
            return false;
        }

        return helper(root->left,Min,root)&& helper(root->right,root,Max);
    }

    bool isValidBST(TreeNode* root) {

    return helper(root,NULL,NULL);     
    }
};