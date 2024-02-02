class Solution {
public:
    int numTrees(int n) {
        vector<int> num(n+1,1);
        for(int i = 2; i <= n; i++)
        {
            int val = 0;
            for(int j = 0;j<i;j++)
            {
                val = num[j]*num[i-j-1] + val;
            }
            num[i] = val;
        }
        return num[n];
    }
};