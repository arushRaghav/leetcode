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
    
    bool equal(TreeNode* l, TreeNode* r)
    {
        if(l == NULL && r == NULL)
            return true;
        if(l == NULL || r == NULL)
            return false;
        
        if(l->val != r->val)
            return false;

        bool fi = equal(l->left , r->right);
        bool se = equal(l->right , r->left);
        return fi&&se;
    }
    
    bool isSymmetric(TreeNode* root) {
        return equal(root->left,root->right);
    }
};