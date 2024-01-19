class Solution {
public:

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<bool> check(n,false);
        for(int i = 0;i<edges.size();i++)
        {
            check[edges[i][1]] = true;
        }
        for(int i = 0;i<n;i++)
        {
            if(!check[i])
                ans.push_back(i);
        }
        return ans;
    }
};