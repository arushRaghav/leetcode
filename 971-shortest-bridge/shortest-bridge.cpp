class Solution {
public:
    vector<pair<int,int>> border;
    
    void prin(vector<pair<int,int>> & a)
    {
        for(int i = 0; i< a.size();i++)
        {
            cout<<a[i].first<<a[i].second<<"   ";
        } cout<<'\n';
    }

    void prinMat(vector<vector<int>>& mat)
    {
        for(int i=0;i<mat.size();i++)
        {
            for(int j = 0;j<mat.size();j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    bool findWater( vector<vector<int>>& grid , int x, int y )
    {
        if( (x>0 && grid[x-1][y] == 0) || ( x < grid.size()-1 && grid[x+1][y] == 0 ) || (y>0 && grid[x][y-1] == 0) || ( y < grid.size()-1 && grid[x][y+1] == 0 ))
            return true;
        return false;
    }
    vector<int> findFirstIsland( vector<vector<int>>& grid )
    {
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid.size();j++)
            {
                if( grid[i][j] == 1 )
                { vector<int> a{i,j}; return a; }
            }
        }
        vector<int> a{0,0};
        return a;
    }

    void traverse(int x,int y, vector<vector<int>>& grid)
    {
        grid[x][y] = 2;

        if(findWater(grid , x,y))
            border.push_back({x,y});
        if(x>0 && grid[x-1][y] == 1 ) traverse(x-1,y,grid);
        if(y>0 && grid[x][y-1] == 1 ) traverse(x,y-1,grid);
        if(x<grid.size()-1 && grid[x+1][y] == 1 ) traverse(x+1,y,grid);
        if(y<grid.size()-1 && grid[x][y+1] == 1 ) traverse(x,y+1,grid);

    }


    int shortestBridge(vector<vector<int>>& grid) 
    {
        vector<int> a;
        a = findFirstIsland(grid);
        traverse(a[0],a[1],grid);
        //now we are getting border successfully and have figured out the first island
        //now find minimum depth 
        //prinMat(grid);
        int ans = 0;
        while(border.size()!=0)
        {
            pair<int,int> i = border[0];                                           
            border.erase(border.begin());
            int d = 0; vector<vector<int>> ser = grid;
            vector<pair<int,int>> curr; vector<pair<int,int>> child;
            curr.push_back(i);  bool found = false; //cout<<"a";
            while( curr.size()!=0)
            {
                i = curr[0]; curr.erase(curr.begin());
                int xi = i.first , yi = i.second;
                ser[xi][yi] = 3;   
                if( (xi>0 && grid[xi-1][yi] == 1) || ( xi < grid.size()-1 && grid[xi+1][yi] == 1 ) || (yi>0 && grid[xi][yi-1] == 1) || ( yi < grid.size()-1 && grid[xi][yi+1] == 1 ))
                { found = true;  break;}

                if(xi>0 && ser[xi-1][yi] == 0 ) {child.push_back({xi-1,yi}); ser[xi-1][yi] = 3; }
                if(xi<ser.size()-1 && ser[xi+1][yi] == 0 ) {child.push_back({xi+1,yi}); ser[xi+1][yi] = 3; }
                if(yi>0 && ser[xi][yi-1] == 0 ) {child.push_back({xi,yi-1}); ser[xi][yi-1] = 3; }
                if(yi<ser.size()-1 && ser[xi][yi+1] == 0 ) {child.push_back({xi,yi+1}); ser[xi][yi+1] = 3;}


                //cout<<"  curr = "<<curr.size();
                //cout<<"  child = "<<child.size();
                if(curr.size() == 0)
                {
                    curr = child;
                    d++;
                    child.clear();//prinMat(ser); 
                    //cout<<d<<"a"<<curr.size()<<"\n\n";
                }
                //cout<<"  child af = "<<child.size();

            }
            
            if(found)
            {
            if(ans == 0)
            { ans = d; }
            ans = min(ans,d);
            if(d == 1) return 1;
            }
        }
        //cout<<'\n';
        return ans;
    }
};