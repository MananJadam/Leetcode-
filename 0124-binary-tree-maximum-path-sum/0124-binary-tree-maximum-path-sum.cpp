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
    int findSum(TreeNode*node,int &maxi){
        if(node==NULL){
            return 0;
        }
        int ls=max(0,findSum(node->left,maxi));
        int rs=max(0,findSum(node->right,maxi));
        maxi=max(maxi,ls+rs+node->val);
        return (node->val)+max(ls,rs);

    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        findSum(root,maxi);
        return maxi;
    }
};