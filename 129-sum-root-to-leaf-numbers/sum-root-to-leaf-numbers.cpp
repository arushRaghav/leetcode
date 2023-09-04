class Solution {
public:
    int sum = 0; 
    void helper(TreeNode* rt, int n){
    n = (n*10) + rt->val;

    if(rt->left == NULL && rt->right == NULL){
    sum += n;
    return;
    }
 
    if(rt->left)
        helper(rt->left, n);
    if(rt->right)
        helper(rt->right, n);
    }


    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        return sum;
    }
};