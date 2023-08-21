class Solution {
public:
    vector<int> mem;
    
    void make_mem(int n)
    {
        for(int i = mem.size() ;i<n;i++)
        {
            if(i == 0 || i == 1)
                mem.push_back(1);
            else
                mem.push_back(mem[i-1]+mem[i-2]);
        }
    }

    int climbStairs(int n) {
        if(n == 0|| n == 1)
            return 1;
        else if(mem.size()>=n)
        {
            return mem[n-1] + mem[n-2];
        }
        else
        {
            make_mem(n);
            return mem[n-1]+mem[n-2];
        }
            
    }
};