class Solution {
public:
    
    int mini(vector<vector<int>>& matrix, int row , int col , vector<vector<int>>& dp)
    {
        if(row>=0&&row<matrix.size() && col>=0&&col<matrix.size())
        {
            if(row == matrix.size()-1)
            {
                return matrix[row][col];
            }
            if(dp[row][col] != INT_MIN)
                return dp[row][col];
            dp[row][col] = matrix[row][col] + min({mini(matrix,row+1,col-1,dp),mini(matrix,row+1,col+1,dp),mini(matrix,row+1,col,dp)});
            return dp[row][col];
        }
        return INT_MAX;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix.size(),INT_MIN));
        int ans = INT_MAX;
        for(int i = 0;i<matrix.size();i++)
        {
            ans = min(ans,mini(matrix,0,i,dp));
        }
        return ans;
    }
};