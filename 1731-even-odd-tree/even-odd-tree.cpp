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

        bool travel(TreeNode* root, int level, vector<int>& le){
        if(root != NULL){
            if((level+1)%2 == 0){
                if(root->val % 2 != 0)
                    return false;
                if(le.size() <= level){
                    le.push_back(root->val);
                }
                else{
                    if(le[level] <= root->val)
                        return false;
                    le[level] = root->val;
                }
            }
            else{
                if(root->val % 2 == 0){
                    return false;
                }
                if(le.size() <= level){
                    le.push_back(root->val);
                }
                else{
                    if(le[level] >= root->val)
                        return false;
                    le[level] = root->val;
                }
            }
            level++;
            return (travel(root->left,level,le) && travel(root->right,level,le) );    
        }
        return true;
    }

    bool isEvenOddTree(TreeNode* root) {
        vector<int> le;
        return travel(root,0,le);
    }
};