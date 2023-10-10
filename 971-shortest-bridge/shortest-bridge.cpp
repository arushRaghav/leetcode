class Solution {
private:
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void addNodesToQueue(vector<vector<int>>& grid, int m, int n,
                         int i, int j, int color, queue<pair<int, int>>& q) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1 || grid[i][j] == color) {
            return;
        }

        grid[i][j] = color;
        q.push(make_pair(i, j));
    
        for (auto& d : directions) {
            int n_i = i + d[0];
            int n_j = j + d[1];
            addNodesToQueue(grid, m, n, n_i, n_j, color, q);
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 1. Add the nodes of the first island to queue.
        int color = 2;
        queue<pair<int, int>> q;
        for (int i = 0, added = 0; i < m && !added; ++i) {
            for (int j = 0; j < n && !added; ++j) {
                if (grid[i][j] == 1) {
                    addNodesToQueue(grid, m, n, i, j, color, q);
                    added = 1;
                }
            }
        }
        
        // 2. BFS from the queue that contains the nodes from the first island.
        int level = 0;
        while (!q.empty()) {
            // Iterates the nodes in the current level.
            int level_len = q.size();
            for (int i = 0; i < level_len; ++i) {
                pair<int, int> curr = q.front();
                q.pop();

                for (auto& d : directions) {
                    int n_i = curr.first + d[0];
                    int n_j = curr.second + d[1];
                    if (n_i < 0 || n_j < 0 || n_i >= m || n_j >= n || grid[n_i][n_j] == 2) {
                        continue;
                    }
                    if (grid[n_i][n_j] == 1) {
                        return level;
                    }

                    grid[n_i][n_j] = 2;
                    q.push(make_pair(n_i, n_j));
                }
            }

            ++level;
        }
        return level;
    }
};
