class Solution {
public:

    struct Node{
        int x , y , dist;
    };
    bool isValid(vector <vector <char>> &arr , vector <vector <bool>> &vis , int i , int j , int m , int n){
        if (i >= 0 and i < n and j >= 0 and j < m and !vis[i][j] and arr[i][j] == '.'){
            return true;
        }
        return false;
    }
    int nearestExit(vector<vector<char>>& arr, vector<int>& en) {
        int n = arr.size();
        int m = arr[0].size();
        vector <vector <bool>> vis(n , vector <bool> (m ,false));
        int dx[] = {1 , 0 , -1 , 0};
        int dy[] = {0 , 1 , 0 , -1};
       

        int x = en[0] , y = en[1];
        
        queue <Node> q;
        int min_dist = 1e9;
        q.push({x , y , 0});
        vis[x][y] = true;
        while(!q.empty()){
            Node cur = q.front();
            q.pop();
            int i = cur.x , j = cur.y , dist = cur.dist;
            if (((i == 0 || i == n - 1) || (j == 0 || j == m - 1)) and arr[i][j] == '.'){
                if (i == x and j == y){

                }else{
                min_dist = dist;
                break;
                }
            }
            cout << min_dist << endl;
            for (int k = 0; k < 4; k++){
                int ti = i + dx[k] , tj = j + dy[k];
                if (isValid(arr , vis , ti , tj , m , n)){
                    vis[ti][tj] = true;
                    q.push({ti , tj , dist + 1});
                    
                }
            }
            cout << min_dist << endl;
        }

        if (min_dist == 1e9){
            return -1;
        }else return min_dist;



    }
};