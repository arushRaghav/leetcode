class Solution {
public:
    int calculate(string s) {

        vector<int> stak;
        vector<int> sn;
        int an =0;    
        int sign = 1;
        for(int i = 0; i<s.length(); i++)
        {
            int c = 0;
            while(isdigit(s[i+c]))
            {
                c++;
            }
            int num =0 ;
            int k = c;
            for(int j = 0; j<k;j++)
            {
                num = (int)pow(10,c-1)*((int)s[i+j] -48) +num ;
                c--;
            }
            if(k>0)
            {
                an = an + sign*num;
                i = i+k-1;
                continue;
            }


            if(s[i] == '+')
            {
                sign = 1;
            }
            if(s[i] == '-')
            {
                sign = -1;
            }

            if(s[i] == '(')
            {
                stak.push_back(an);
                sn.push_back(sign);
                sign = 1;
                an = 0;
            }

            if(s[i] == ')')
            {
                an = stak[stak.size()-1] + sn[sn.size()-1]*an;
                stak.pop_back();
                sn.pop_back();
            }
        }

    return an;
    }
};