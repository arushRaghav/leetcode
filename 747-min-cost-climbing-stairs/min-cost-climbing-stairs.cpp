class Solution {
public:
    
    vector<int> s;
    int minc(vector<int>& st ,int n)
    {
        if(s.size()>n-2)
        {
            return s[n-2];
        }
        if(n == 1  || n == 0)
        {
            return st[n];
        }
        s.push_back(st[n] + min(minc(st,n-1) , minc(st,n-2)));
        return st[n] + min(minc(st,n-1) , minc(st,n-2));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        return min(minc(cost,cost.size()-1),minc(cost,cost.size()-2));
    }
};