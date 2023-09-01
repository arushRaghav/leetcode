class Solution {
public:
    
    vector<int> rb;
    void ini(vector<int>& ar)
    {
        for(int i =0;i<ar.size();i++)
            rb.push_back(-1);
    }

    int ma(vector<int>& st, int n)
    {
        if(rb[n]>=0)
        {
            return rb[n];
        }
        if(n<3)
        {
            if(n == 2)
            {
                return st[2] + st[0];
            }
            else
            {
                return st[n];
            }
        }
        else
        {
            rb[n] = st[n] + max(ma(st,n-2) , ma(st,n-3));
            return rb[n];
        }
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return nums[0];
        }
        ini(nums);
        return max(ma(nums , nums.size()-1),ma(nums,nums.size()-2));
    }
};