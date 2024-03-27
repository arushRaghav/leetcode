class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        vector<int> num;
        while(i+j<n+m){
            if(i<m && j<n){
                if(nums1[i]<nums2[j]){
                    num.push_back(nums1[i]);
                    i++;
                }
                else{
                    num.push_back(nums2[j]);
                    j++;
                }
            }
            else if(j<n){
                num.push_back(nums2[j]); j++;
            }
            else{
                num.push_back(nums1[i]);
                i++;
            }
        }
        nums1 = num;
    }
};