class Solution {
public:
    int numSquares(int n) {
        vector<int> num(n+1,1);

        if( floor(sqrt(n)) == sqrt(n) )
            return 1;

        for(int i = 2;i<=n;i++)
        {
            if(floor(sqrt(i)) == sqrt(i))
            {
                num[i] = 1;
                continue;
            }
            int val = INT_MAX;
            for(int j = 1;j<= i/2;j++)
            {
                val = min( val , (num[j] + num[i-j]) );
            }
            num[i] = val;
        }
        return num[n];
    }
};