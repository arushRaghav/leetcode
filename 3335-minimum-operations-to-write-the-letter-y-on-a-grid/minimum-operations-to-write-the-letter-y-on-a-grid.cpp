class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int Y[3]{0,0,0};
        int rest[3]{0,0,0}; int n = grid.size();
        for(int i=0;i<grid.size();i++){
            for(int j=0; j<n;j++){
                if(((j == i || j == n-1-i)&&i<n/2) || ( j == n/2 && i>= n/2 ) ){
                    if(i<n/2){
                        Y[grid[i][j]]++;
                    }
                    else{
                        Y[grid[i][n/2]]++;
                    }
                }
                else
                    rest[grid[i][j]]++;
            }
        }
        int a = max((Y[0]+rest[1]),(Y[0]+rest[2]));
        int b = max((Y[1]+rest[0]),(Y[1]+rest[2]));
        int c = max((Y[2]+rest[0]),(Y[2]+rest[1]));
        return  n*n - max(a,max(b,c));
    }
};