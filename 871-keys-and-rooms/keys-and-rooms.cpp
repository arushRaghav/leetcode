class Solution {
public:
    
    

    void can(int i , vector<bool>& visit , vector<vector<int>>& rooms)
    {
        visit[i] = true;
        //cout<<i<<"\n";
        for(int j = 0;j<rooms[i].size();j++)
        {
            if(!visit[rooms[i][j]])
            {
                can(rooms[i][j] , visit , rooms);
            }
        }
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visit(rooms.size() , false);
        can(0 , visit , rooms);
        bool ans = true;
        for(int i = 0; i<visit.size(); i++)
        {
            ans = ans&&visit[i];
            if(ans == false)
                break;
        }
        return ans;
    }
};