/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    void prin(map<int,vector<int>>& mp , int n)
    {
        for(int i = 0 ; i <=n ; i++)
            cout<<mp[i][0]<<" "<<mp[i][1]<<" "<<mp[i][2]<<'\n';
    }
    void make(TreeNode* node , map<int,vector<int>>& mp , int paVal , int max)
    {
        if(node != NULL)
        {
            int right = -1 , left = -1;
            if(node->left!=NULL)
            {
                left = node->left->val;
            }
           if(node->right!=NULL)
            {
                right = node->right->val;
            }
            if(max<node->val)
                max = node->val;
            vector<int> te{ paVal , right , left };
            mp[node->val] = te;
            make(node->left , mp , node->val , max);
            make(node->right , mp , node->val , max);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k ) 
    {
        vector<int> ans;
        map<int,vector<int>> mp;  int max = root->val;
        int right = -1 , left = -1;
        if(root->left!=NULL)
        {
            left = root->left->val;
        }
       if(root->right!=NULL)
        {
            right = root->right->val;
        }
        mp[root->val] = {-1 , right , left};

        make(root->left , mp , root->val , max);
        make(root->right , mp , root->val , max);
        //map made sucessfully

        vector<int> visiting;
        vector<int> toBeVisited;
        vector<bool> visited(max+2000 , false);
        visiting.push_back(target->val);

        while(visiting.size()>0)
        {
            int i = visiting[visiting.size()-1];
            visiting.pop_back();
            if(!visited[i])
            { 
            visited[i] = true;
            if(k == 0)
            {
                ans.push_back(i);
            }
            for(int j = 0 ; j<=2 ; j++)
            {
                if(mp[i][j]!= -1)
                    toBeVisited.push_back(mp[i][j]);
            }
            }
            if(k!=0 && visiting.size() == 0)
            {
                visiting = toBeVisited;
                toBeVisited.clear();
                k--;
            }          
        }
        return ans;
    }
};