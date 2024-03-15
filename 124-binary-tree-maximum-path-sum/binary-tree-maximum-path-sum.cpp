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

    int nodeMax(TreeNode* nod,int& ans){
        if(nod == NULL)
            return 0;
        int l = nodeMax(nod->left,ans);
        int r = nodeMax(nod->right,ans);
        int con = max(l+nod->val,max(r+nod->val,nod->val));
        int ma = max(con,nod->val+l+r);
        ans = max(ans,ma);
        return con;
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        nodeMax(root,ans);
        return ans;
    }
};