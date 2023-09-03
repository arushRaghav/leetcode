class Solution {
public:
    
    
    int pam(vector<vector<int>>& gr,int m,int n , vector<vector<int>>& st)
    {
        
        if(st[m][n] >= 0)
        {
            return st[m][n];
        }
        
        if(m == 0 && n == 0)
        {
            return gr[0][0];
        }
        else if(m == 0)
        {
            st[m][n] = gr[m][n] + pam(gr , m , n-1 ,st);
            return st[m][n] ;
        }
        else if(n == 0)
        {
            st[m][n] = gr[m][n] + pam(gr , m-1 , n , st);
            return st[m][n];
        }
        else
        {
            st[m][n] = gr[m][n] + min(pam(gr,m-1,n,st),pam(gr,m,n-1,st));
            return st[m][n];
        }
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> sto(m , vector<int>(n,-1));
        return pam(grid,m-1,n-1,sto);
    }
};