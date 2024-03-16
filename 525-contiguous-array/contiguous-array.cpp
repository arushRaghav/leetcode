class Solution {
public:

    void prin(vector<int> s){
        for(int i=0;i<s.size();i++){
            cout<<s[i]<<" ";
        }cout<<"\n";
    }
    int findMaxLength(vector<int>& nums) {
        map<int,int> sum; vector<int> su(nums.size()+1,0);
        sum[0] = 0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                su[i+1] = su[i] +1;
            }
            else{
                su[i+1] = su[i] -1;
            }
            if(!sum[su[i+1]] && su[i+1] != 0){
                sum[su[i+1]] = i+1; //cout<<su[i+1]<<" ";
            }
            else{
                ans = max(ans , i+1 - sum[su[i+1]]);
            }
        }
        // cout<<"\n";
        // prin(su);
        return ans;
    }
};