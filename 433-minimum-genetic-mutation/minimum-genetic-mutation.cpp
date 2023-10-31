class Solution {
public:
    
    int diff(string st , string ed)//find no. of diffrences
    {
        int d = 0;
        for(int i = 0 ; i < 8 ; i++)
        {
            if(st[i] != ed[i])
                d++;
        }
        return d;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // let i be the current node
        vector<int> toBeVisited;
        vector<int> visiting;
        vector<bool> visited(bank.size() , false);
        bank.push_back(startGene);
        int  i = bank.size()-1;
        visiting.push_back(i);

        int de =0; bool found = false;
        while(visiting.size() != 0)
        {
            i = visiting[visiting.size()-1];
            visiting.pop_back();
            if(endGene == bank[i])
            {
                found = true;
                break;
            }
            for(int j = 0;j<visited.size();j++)
            {
                if(!visited[j] && diff(bank[j] , bank[i]) ==1)
                {
                    visited[j] = true;
                    toBeVisited.push_back(j);
                }
            }

            if(visiting.size() == 0 && toBeVisited.size()!=0)
            {
                visiting = toBeVisited;
                toBeVisited.clear();
                de++;
            }
        }
        if(found)
            return de;
        return -1;
    }
};