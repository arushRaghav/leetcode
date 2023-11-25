class Solution {
public:
    
    bool check(int i , int j ,vector<vector<int>>& grid , int& la)
    {
        
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() )
        {
            if(grid[i][j] == 1)
            {
                bool ch = false;la++;
                grid[i][j] = 0;
                if(i == 0 || j == 0 || i == grid.size()-1 || j == grid[0].size()-1 )
                {
                    //cout<<i<<" "<<j<<"c\n"; 
                    ch = true;
                }
                bool l = check(i-1,j,grid,la) , r = check(i+1,j,grid,la) , t = check(i,j-1,grid,la) ,b = check(i,j+1,grid,la);
                return l||b||r||t||ch;
            }
            return false;
        }
        return false;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;


        for(int i = 0; i<grid.size(); i++)
        {
            for(int j = 0; j<grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    //cout<<i<<" "<<j<<"b\n";
                    int an = 0;
                    if(!check(i,j,grid,an))
                    {
                        //cout<<i<<" "<<j<<"a\n";
                        ans = an + ans;
                    }
                }
            }
        }
        return ans;
    }
};