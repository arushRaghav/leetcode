class Solution {
public:
    int sum = 0; 
    void helper(TreeNode* rt, int n){
    
    if(rt == NULL){
    return;
    }
    n = (n*10) + rt->val;

    if(rt->left == NULL && rt->right == NULL){
    sum += n;
    return;
    }
 
    helper(rt->left, n);
    helper(rt->right, n);
    }


    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        return sum;
    }
};