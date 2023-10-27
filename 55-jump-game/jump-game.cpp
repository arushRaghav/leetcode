class Solution {
public:
    
    bool zero(int zero , vector<int>& nums)
    {
        for(int i = zero; i>=0 ; i--)
        {
            if(zero-i < nums[i])
            {
                return jump(i,nums);
            }
        }
        return false;
    }
    
    bool jump(int end ,  vector<int>& nums)
    {
        for(int i = end -1 ; i>=0 ; i--)
        {
            if(nums[i] == 0)
            return zero(i,nums);
        }
        return true;
    }
    
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
        return true;
        return jump(nums.size()-1 , nums);
    }
};