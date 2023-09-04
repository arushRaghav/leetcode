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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root != NULL)
        {
            if(root->val == targetSum && root->left == NULL && root->right == NULL )
                return true;
            
            else if(root->val != targetSum && root->left == NULL && root->right == NULL)
                return false;
            else if( root->left != NULL && root->right != NULL )
                return hasPathSum( root->left , targetSum - root->val ) || hasPathSum(root->right , targetSum - root->val);
            
            else if(root->left == NULL)
                return hasPathSum(root->right , targetSum - root->val);
            
            else
                return hasPathSum(root->left , targetSum - root->val);
        }

        else
            return false;
    }
};