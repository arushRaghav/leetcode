class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> longe(nums.size() , 1);

        for(int i = 0; i<nums.size() ; i++)
        {
            int ma = INT_MIN;
            for(int j = 0; j<i ; j++)
            {
                if(nums[i] > nums[j])
                {
                    ma = max(ma , longe[j]);
                }
            }
            if(ma>0)
                longe[i] = ma + 1;
        }
        int ans = 0;
        for(int i = 0; i<nums.size();i++)
        {
            if( ans < longe[i] )
                ans = longe[i];
        }
        return ans;
    }
};