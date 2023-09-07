class Solution {
public:
    
    void ini(vector<int>& nu, int n)
    {
        for(int i =1;i<=n;i++)
        {
            nu.push_back(i);
        }
    }


    vector<vector<int>> ans;
    void com(vector<int>& n ,vector<int> lan , int k)
    {
        k--;
        if(k<0)
        {
            ans.push_back(lan);
            return;
        }
        else
        {
            for(int i = 0 ; i<n.size() ; i++)
            {
                lan.push_back(n[i]);
                vector<int> sa = n;
                sa.erase(sa.begin(),sa.begin()+i+1);
                com(sa,lan,k);
                lan.pop_back();
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> nu;
        ini(nu,n);
        vector<int> l;
        com(nu,l,k);
        return ans;
    }
};