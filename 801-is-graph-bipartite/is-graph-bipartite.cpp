class Solution {
public:
    
    // void prin(vector<int>& vec)
    // {
    //     for(int i = 0;i<vec.size();i++)
    //     {
    //         cout<<vec[i]<<" ";
    //     }cout<<"\n";
    // }

    void gen(vector<int>& visiting , vector<bool>& dis)
    {
        for(int i = 0; i<dis.size();i++)
        {
            if(!dis[i])
            { visiting.push_back(i); break; }
        }
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> dis(graph.size(),false);
        vector<int> col(graph.size(),-1);
        vector<int> visiting;
        vector<int> toVisit;

        gen(visiting,dis);
        bool ph = true;//true = 0 , false = 1
        col[0] = 0;
        while(visiting.size()!=0)
        {
            int node = visiting[visiting.size()-1];
            visiting.pop_back();
            dis[node] = true;
            //cout<<node<<" "<<ph<<"\n";
            if(ph)
            {
                for(int j = 0;j<graph[node].size();j++)
                {
                    if(col[graph[node][j]] == 0 )
                        return false;
                    if(col[graph[node][j]] == -1)
                    {
                        col[graph[node][j]] = 1;
                        toVisit.push_back( graph[node][j] );
                    }
                }
            }

            else
            {
                for(int j = 0;j<graph[node].size();j++)
                {
                    if(col[graph[node][j]] == 1 )
                        return false;
                    if(col[graph[node][j]] == -1)
                    {
                        col[graph[node][j]] = 0;
                        toVisit.push_back( graph[node][j] );
                    }
                }
            }
            //prin(col);
            if(visiting.size() == 0 && toVisit.size() !=0)
            {
                visiting = toVisit;
                toVisit.clear();
                if(ph)
                    ph = false;
                else
                    ph = true;
                continue;
            }
            if(visiting.size()==0)
                gen(visiting,dis);
        }
        return true;
    }
};