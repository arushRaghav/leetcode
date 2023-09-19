class Solution {
public:
    
    int mnt(vector<vector<int>>& tri , int i , int lev , vector<vector<int>>& ch )
    {
        if(ch[lev][i]>INT_MIN)
            return ch[lev][i];
        if(lev == tri.size()-1)
            return tri[lev][i];
        ch[lev][i] = tri[lev][i] + min( mnt(tri , i , lev + 1 ,ch) , mnt(tri , i + 1 , lev + 1,ch) );
        return ch[lev][i];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> ch(triangle.size(),vector<int>(triangle.size(),INT_MIN));
        return mnt(triangle , 0,0 , ch);
    }
};