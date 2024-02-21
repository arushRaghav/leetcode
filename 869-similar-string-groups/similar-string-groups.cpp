class Solution {
public:
    
    // void prin(vector<vector<bool>>& mat){
    //     for(int i=0;i<mat.size();i++){
    //         for(int j=0;j<mat[0].size();j++){
    //             cout<<mat[i][j]<<" ";
    //         }cout<<"\n";
    //     }
    // }

    bool iscon(string fi,string se){
        int c =0;
        for(int i=0;i<fi.size();i++){
            if(fi[i]!=se[i])
                c++;
        }
        if(c==2||c==0)
            return true;
        return false;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        vector<vector<bool>> conn(strs.size(),vector<bool>(strs.size(),false));
        for(int i=0;i<strs.size();i++){
            for(int j=i+1;j<strs.size();j++){
                if(iscon(strs[i],strs[j])){
                    conn[i][j] = true;
                    conn[j][i] = true;
                }
            }
        }
        
        int ans = 0;
        int left = strs.size();
        vector<bool> seen(strs.size(),false);
        vector<int> next;
        vector<int> child;

        for(int j=0;j<strs.size();j++){
        if(left == 0)
            break;
        if(!seen[j]){
        
        next.push_back(j); seen[j] = true;  left--; ans++;

        while(next.size()!=0){
            int presNode = next[next.size()-1];
            next.pop_back();
            for(int i=0;i<strs.size();i++){
                if( conn[i][presNode] && !seen[i] ){
                    child.push_back(i);
                    seen[i] = true;
                    left--;
                    if(left == 0)
                        break;
                }
            }
            if(next.size()==0&&child.size()!=0){
                next = child;
                child.clear();
            }
        }

        }}
        return ans;
    }
};