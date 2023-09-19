class Solution {
public:
    
    // void prin(vector<vector<int>>& vec)
    // {
    //     for(int i = 0;i<vec.size();i++)
    //     {
    //         for(int j = 0;j<vec[0].size();j++)
    //         {
    //             cout<<vec[i][j]<<" ";
    //         }
    //         cout<<"\n";
    //     }
    // }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        
        vector<vector<int>> db(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        //prin(db);
        int ma = 0;
        for(int i =1;i<=matrix.size();i++)
        {
            for(int j = 1;j<=matrix[0].size();j++)
            {
                int mi = min( min(db[i-1][j-1] , db[i][j-1]) , db[i-1][j]) ;

                if(mi>0 && ((int)matrix[i-1][j-1] - 48)!=0)
                    {
                        db[i][j] = mi +1;
                        ma = max(ma , db[i][j]);
                    }
                else
                    db[i][j] = (int)matrix[i-1][j-1] - 48;
                
                if(ma == 0)
                {

                    if( ((int)matrix[i-1][j-1] - 48) == 1)
                        ma = 1;
                }
            }
            cout<<'\n';
        }
        return ma*ma;
    }
};