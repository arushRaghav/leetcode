class Solution {
public:

    bool reach(vector<int>&arr , vector<bool>& vi , int pos)
    {
        if(pos>=0 && pos< arr.size())
        {
            if( arr[pos] == 0 )
            {
                return true;
            }
            if(vi[pos])
                return false;
            vi[pos] = true;
            return reach( arr, vi , pos - arr[pos] )||reach( arr , vi , pos+arr[pos] );
        }
        return false;
    }
    
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vi(arr.size() , false);

        return reach(arr , vi , start);
    }
};