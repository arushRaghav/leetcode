class Solution {
public:
    string longestPalindrome(string s) 
    {
        vector<vector<bool>> data(s.size(),vector<bool>(s.size(),false));
        int b=0 , len = 1;

        for(int i = 1; i<=s.size() ; i++)
        {
            for(int j = 0 ; j+i<=s.size() ; j++)
            {
                if(i>2 && s[j] == s[j+i-1] && data[j+1][j+i-2] )
                {
                    data[j][j+i-1] = true;
                    data[j+i-1][j] = true;
                    b = j;
                    len = i;
                }
                if(s[j] == s[j+i-1] && i == 2)
                {
                    data[j][j+i-1] = true;
                    data[j+i-1][j] = true;
                    b = j;
                    len = i;                    
                }
                else
                {
                    data[j][j] = true;
                }
            }
        }

        return s.substr(b,len);
    }
};