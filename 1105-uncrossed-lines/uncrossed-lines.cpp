class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> lar(nums1.size() + 1 , vector<int>(nums2.size()+1,0));

        for(int i = 1; i<=nums1.size() ; i++)
        {
            for(int j = 1;j<=nums2.size() ; j++)
            {
                if( nums1[i-1] == nums2[j-1] )
                {
                    lar[i][j] = lar[i-1][j-1] + 1;
                }
                else
                {
                    lar[i][j] = max(lar[i-1][j] , lar[i][j-1]);
                }
            }
        }
        return lar[nums1.size()][nums2.size()];
    }
};