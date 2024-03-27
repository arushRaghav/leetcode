class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& n, int k) {
        if(k==0) return 0;
        long long int rp = 1;
        int res = 0;
        int ri = 0;
        for(int i=0;i<n.size();i++){
            rp = rp * n[i];
            while(rp >= k && i>=ri) {
                rp = rp / (n[ri++]);
            }
            res = res + (i-ri+1);
        }
        return res;
    }
};