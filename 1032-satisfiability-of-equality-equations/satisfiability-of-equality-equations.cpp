class Solution {
public:

    // void prin(vector<vector<bool>>& mat){
    //     for(int i = 0;i<mat.size();i++){
    //         for(int j=0;j<mat[0].size();j++){
    //             cout<<mat[i][j]<<" ";
    //         }cout<<"\n";
    //     }
    // }

    void df( vector<vector<bool>>& mat , vector<int>& group , int& k, int index ){
        group[index] = k;
        for(int i=0;i<26;i++){
            if( mat[index][i] && group[i] == -1 ){
                df(mat,group,k,i);
            }
        }
    }

    bool equationsPossible(vector<string>& equations) {
        vector<vector<bool>> con(26,vector<bool>(26,false));
        vector<int> group(26,0);
        int no = 0;
        for(int i =0;i<equations.size();i++){
            if(equations[i][1] == '='){
                int fi = (int)equations[i][0] - 97;
                int se = (int)equations[i][3] - 97;
                if(fi == se)
                    continue;
                con[fi][se] = true;
                con[se][fi] = true;
                group[fi] = -1; group[se] = -1;
            }
            else{
                no++;
            }
        }
        int k = 1;
        for(int i=0;i<26;i++){
            if(group[i] == -1){
                df(con,group,k,i);
                k++;
            }
        }

        for(int i=0;i<equations.size();i++){
            cout<<i<<" ";
            if(no == 0)
                break;
            if(equations[i][1] == '!'){
                int fi = (int)equations[i][0] - 97;
                int se = (int)equations[i][3] - 97;
                if((group[fi] == group[se] && group[fi] != 0)|| fi == se)
                    return false;
                no--;
            }
        }

        return true;
    }
};