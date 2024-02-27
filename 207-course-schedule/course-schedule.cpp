class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> inDeg(n, 0);
        for(const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            inDeg[pre[0]]++;
        }

        unordered_set<int> v;
        deque<int> q;
        for(int i = 0; i < n; ++i) {
            if(inDeg[i] == 0) {
                v.insert(i);
                q.push_back(i);
            }
        }
        while(!q.empty()) {
            int cur = q.front(); q.pop_front();
            for(auto nxt : adj[cur]) {
                if(--inDeg[nxt] == 0) {
                    q.push_back(nxt);
                    v.insert(nxt);
                }
            }
        }

        return (v.size() == n);
    }
};