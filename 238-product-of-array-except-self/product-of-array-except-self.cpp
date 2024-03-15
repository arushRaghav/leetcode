class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros = 0;vector<int> ans; int pro = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zeros++;
                if(zeros == 2)
                    break;
                continue;
            }
            pro = pro*nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(zeros == 1){
                if(nums[i]==0)
                    ans.push_back(pro);
                else
                    ans.push_back(0);
            }
            else if(zeros==2){
                ans.push_back(0);
            }
            else{
                ans.push_back(pro/nums[i]);
            }
        }
        return ans;
    }
};