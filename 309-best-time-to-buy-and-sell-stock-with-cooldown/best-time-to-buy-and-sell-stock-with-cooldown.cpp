class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[1][1]=-1*p[0];
        for(int i=2;i<=n;i++){
            for(int j=0;j<2;j++){
                if(j){
                    dp[i][j]=max(-1*p[i-1]+dp[i-2][0] , dp[i-1][1]);
                }
                else {
                    dp[i][j]=max(p[i-1]+dp[i-1][1],dp[i-1][0]);
                }
            }
        }
        return dp[n][0];
    }
};