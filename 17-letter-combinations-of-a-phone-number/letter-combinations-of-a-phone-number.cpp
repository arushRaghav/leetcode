class Solution {
public:
    
    vector<vector<char>> darr;
    void ini() //to initialise
    {
    darr.push_back({'a','b','c'});
    darr.push_back({'d','e','f'});
    darr.push_back({'g','h','i'});
    darr.push_back({'j','k','l'});
    darr.push_back({'m','n','o'});
    darr.push_back({'p','q','r','s'});
    darr.push_back({'t','u','v'});
    darr.push_back({'w','x','y','z'});
    }


//function for removing first pos
    string mod(string st)
{
    if(st.size() <= 1)
    {
        return "";
    }
    string s = "";
    for(int i = 1; i < st.size(); i++)
    {
        s = s + st[i];
    }
    return s;
}
//function end

    vector<string> ans;
    void letter(string di , string st)
    {
        if(di == "")
        {
            ans.push_back(st);
            return;
        }

        int digit = (int)di[0] - 48;

        di = mod(di);
        for(int i = 0;i<darr[digit - 2].size() ; i++)
        {
            st = st + darr[digit - 2][i];
            letter(di,st);
            st.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        ini(); // initialise darr

        if(digits == "")
            return ans;
        letter(digits , "");
        return ans;
    }
};