class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size(), prev, ans=INT_MAX;
        if(m==1) return triangle[0][0];
        vector<int> dp(m, 0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                if(i==0 && j==0) dp[j]=prev=triangle[i][j];
                else
                {
                    int up=INT_MAX,uleft=INT_MAX;
                    if(j<i) up=dp[j];
                    if(j>0) uleft=prev;
                    prev=up;
                    dp[j]=min(up, uleft)+triangle[i][j];
                    if(i==m-1) ans=min(dp[j], ans);
                }
            }
        }
        return ans;
    }
};