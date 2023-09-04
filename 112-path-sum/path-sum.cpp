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
        if(root == NULL)
            return false;
        queue<pair<TreeNode* , int>> qu;
        qu.push(make_pair(root,root->val));

        while(!qu.empty())
        {
            int size = qu.size();
            for(int i = 0;i<size;i++)
            {
                TreeNode* node = qu.front().first;
                int su = qu.front().second;
                qu.pop();

                if(node->left)
                    qu.push( {node->left , node->left->val + su} );
                if(node->right)
                    qu.push( {node->right , node->right->val + su} );
                if(!node->left && !node->right && su == targetSum)
                    return true;
            }
        }

        return false;
    }
};