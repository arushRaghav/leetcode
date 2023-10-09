class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int, int>> q;
        vector<pair<int, int>> move = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        q.push({e[0], e[1]});

        int count = -1;
        while (!q.empty()){
            int size = q.size();
            count++;

            for (int i = 0; i < size; i++){
                int ii = q.front().first;
                int jj = q.front().second;
                maze[ii][jj] = '+';

                q.pop();

                for (auto it: move){
                    int x = ii + it.first;
                    int y = jj + it.second;

                    if ((x >= 0 && x < n) && (y >= 0 && y < m) && (maze[x][y] == '.')){
                        maze[x][y] = '+';
                        q.push({x, y});
                    }
                }
                if (ii == e[0] && jj == e[1]){
                    continue;
                }
                if (ii == 0 || ii == n - 1 || jj == 0 || jj == m - 1){
                    return count;
                }
            }
        }

        return -1;
    }
};