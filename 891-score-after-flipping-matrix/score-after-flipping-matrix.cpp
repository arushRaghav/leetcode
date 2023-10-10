class Solution {
public:
    void fliprow(int &r,vector<vector<int>>& grid) //function to toggle row
    {
        for(int i=0; i<grid[0].size(); i++){
            grid[r][i]=1-grid[r][i];
        }
    }

    void flipcol(int &c,vector<vector<int>>& grid){ //function to toggle column
        for(int j=0; j<grid.size(); j++){
            grid[j][c]=1-grid[j][c];
        }
    }

    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
//Making the MSB to 1, all values in column 0 should be 1 to get max value
        for(int i=0; i<n; i++){
            if(grid[i][0]==0){    
                fliprow(i,grid);
            }
        }
//traversing and checking which colums have more zeroes than 1, toggling them too
        for(int j=0; j<m; j++){
            int cnt0=0;
            int cnt1=0;
            for(int i=0; i<n; i++){
                if(grid[i][j]==0) cnt0++;
                else cnt1++;
            }
            if(cnt0>cnt1){
                flipcol(j,grid);
            }
        }
//finally calculating the ans
        int sum=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    sum+= (1<<(m-j-1));
                }
            }
        }
        return sum;
        

    }
};