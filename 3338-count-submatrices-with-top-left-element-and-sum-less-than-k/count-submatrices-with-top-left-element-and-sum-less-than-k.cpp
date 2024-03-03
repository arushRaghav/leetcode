class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int r = grid.size() , c = grid[0].size();
        vector<vector<int>> mat(r+1,vector<int>(c+1,0)) , row(r+1,vector<int>(c+1,0));
        int ans = 0;
        for(int i =1;i<=r;i++){
            for(int j=1;j<=c;j++){
                mat[i][j] = mat[i-1][j] + row[i][j-1] + grid[i-1][j-1];
                row[i][j] = row[i][j-1] + grid[i-1][j-1];
                if(mat[i][j]>k){
                    j = c+1; continue;
                }
                ans++;
            }
        }
        return ans;
    }
};