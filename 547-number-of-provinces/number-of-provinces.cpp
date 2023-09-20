class Solution {
public:
    
    int selectNode(vector<bool>& tra , vector<int>& con)
    {
        int i = 0;
        while(i<tra.size())
        {
            if(!tra[i] && con[i] == 1)
            {
                return i;
            }
            i++;
        }
        return -1;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> comptra(isConnected.size(),1);
        vector<bool> tra(isConnected.size(),false);
        vector<int> sta;
        int c = 0;

        //i means current node , j is searching
        while(selectNode(tra , comptra) > -1)
        {

        int i = selectNode(tra , comptra);
        sta.push_back(i);
        tra[i] = true;
        while(sta.size() != 0)
        {
    
            i = selectNode(tra , isConnected[i]);
            if(i>=0)
            {
                sta.push_back(i);
                tra[i] = true;
            }
            else
            {
                sta.pop_back();
                if(sta.size() != 0)
                i = sta[sta.size()-1];
            }
        }

        c++;

        }


        return c;
    }
};