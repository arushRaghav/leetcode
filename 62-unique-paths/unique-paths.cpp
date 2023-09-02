class Solution {
public:
    
    int pa(int m,int n ,vector<vector<int>>& pos)
    {
        if(pos[m-1][n-1] >= 0 )
        {
            return pos[m-1][n-1];
        }
        
        if(m == 1 && n == 1)
        {
            return 1;
        }
        else if(m == 1)
        {
            return 1;
        }
        else if(n == 1)
        {
            return 1;
        }
        else
        {
            pos[m-1][n-1] = pa(m-1,n,pos) + pa(m,n-1,pos);
            return pos[m-1][n-1];
        }
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> pos(m,vector<int>(n,-1));
        return pa(m,n,pos);
    }
};