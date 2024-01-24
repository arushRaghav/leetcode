class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,int> lar;
        int ans = 1;
        for(int i = 0; i <arr.size() ; i++)
        {
            if(lar[arr[i]])
            {
                lar[arr[i] + difference ] = lar[arr[i]] + 1;
                ans = max(lar[arr[i]] , ans);
            }
            else
            {
                lar[arr[i]+difference] = 2;
                ans = max(lar[arr[i]] , ans);
            }
        }
        // int ans = 1;
        // for(int i = 0;i<arr.size();i++)
        // {
        //     if(lar[arr[i]])
        // }
        if(difference == 0)
            return ans-1;
        return ans;
    }
};