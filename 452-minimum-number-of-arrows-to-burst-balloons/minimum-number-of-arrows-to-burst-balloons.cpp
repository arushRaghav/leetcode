class Solution {
public:

    // void prin(vector<vector<int>>& p){
    //     for(int i =0;i<p.size();i++){
    //         for(int j=0;j<p[i].size();j++){
    //             cout<<p[i][j]<<" ";
    //         }cout<<"\n";
    //     }
    // }

    int findMinArrowShots(vector<vector<int>>& p) {
        std::sort(p.begin(), p.end(), [](const auto& p1, const auto& p2) {
            return p1[0]<p2[0];
        });

        int ans =1;
        int range = p[0][1] , i=1;
        while(i<p.size()){
            if(p[i][0]>range){
                ans++;
                range = p[i][1];
            }
            else if(p[i][1]<range){
                range = p[i][1];
            }
            i++;
        }

        //prin(p);
        return ans;
    }
};