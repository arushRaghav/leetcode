class Solution {
public:
    int minDistance(string word1, string word2) {

        vector<vector<int>> edge(word1.size() + 1,
                                    vector<int>(word2.size() + 1, 0));
        
        for(int i = 0;i<=word1.size();i++)
            edge[i][0] = i;
        for(int i = 0;i<=word2.size();i++)
            edge[0][i] = i;

        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1])
                    edge[i][j] = edge[i - 1][j - 1];
                else {
                    edge[i][j] = min( min(edge[i - 1][j], edge[i][j - 1]), edge[i-1][j-1]) + 1;
                }
            }
        }
        return edge[word1.size()][word2.size()];
    }
};