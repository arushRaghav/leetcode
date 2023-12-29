class Solution {
public:
    
    bool check(int i , int j , vector<vector<int>>& grid)
    {
        if(i>=0 && i < grid.size() && j >=0 && j < grid[0].size())
        {
            if(grid[i][j] == 1)
                return true;
        }
        return false;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0; j<grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    int tempArea = 0;
                    grid[i][j] = 0;
                    vector<pair<int,int>> discover;
                    vector<pair<int,int>> child;
                    discover.push_back(make_pair(i,j));
                    while(discover.size()>0)
                    {
                        pair<int,int> node = discover[discover.size()-1];
                        discover.pop_back();
                        tempArea++; int ii = node.first; int jj = node.second;
                        if(check(ii-1,jj,grid))
                        {
                            child.push_back(make_pair(ii-1,jj));
                            grid[ii-1][jj] = 0;
                        }
                        if(check(ii+1,jj,grid ))
                        {
                            child.push_back(make_pair(ii+1,jj));
                            grid[ii+1][jj] = 0;
                        }
                        if(check(ii,jj-1,grid ))
                        {
                            child.push_back(make_pair(ii,jj-1));
                            grid[ii][jj-1] = 0;
                        }
                        if(check(ii,jj+1,grid ))
                        {
                            child.push_back(make_pair(ii,jj+1));
                            grid[ii][jj+1] = 0;
                        }
                        if(discover.size() == 0)
                        {
                            if(child.size()!=0)
                            {
                                discover = child;
                                child.clear();
                            }
                        }
                    }
                    area = max(area,tempArea);
                }
                
            }

        }
        return area;
    }
};