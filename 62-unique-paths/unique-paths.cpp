class Solution {
public:
    
    vector<vector<int>> pos;
    void ini(int m , int n)
    {
        vector<int> temp(n,-1);
        for(int j = 0;j<m;j++)
        {
            pos.push_back(temp);
        }
    }
    int pa(int m,int n)
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
            pos[m-1][n-1] = pa(m-1,n) + pa(m,n-1);
            return pos[m-1][n-1];
        }
    }

    int uniquePaths(int m, int n) {
        ini(m,n);
        return pa(m,n);
    }
};