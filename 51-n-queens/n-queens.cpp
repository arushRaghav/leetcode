class Solution {
public:
    void f(vector<string> &board,int c,vector<vector<string>> &vec,vector<int> &row,vector<int> &lowerdiagonal, vector<int> &upperdiagonal,int n){
        if(c==n){
            vec.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(row[i]==0&&lowerdiagonal[c+i]==0&&upperdiagonal[n-1+c-i]==0){
                board[i][c]='Q';
                row[i]=1;
                lowerdiagonal[i+c]=1;
                upperdiagonal[n-1+c-i]=1;
                f(board,c+1,vec,row,lowerdiagonal,upperdiagonal,n);
                board[i][c]='.';
                row[i]=0;
                lowerdiagonal[i+c]=0;
                upperdiagonal[n-1+c-i]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string> board(n);
        vector<vector<string>> vec;
        vector<int>row(n);
        vector<int>lowerdiagonal(2*n-1);
        vector<int>upperdiagonal(2*n-1);
        for(int i=0;i<n;i++){
            row[i]=0;
            board[i]=s;
        }
        for(int i=0;i<2*n-1;i++){
            lowerdiagonal[i]=0;
        }
        for(int i=0;i<2*n-1;i++){
            upperdiagonal[i]=0;
        }
        f(board,0,vec,row,lowerdiagonal,upperdiagonal,n);
        return vec;
    }
};