class Solution {
public:
    int minimumLength(string s) {
        if(s.size()==1)
            return 1;
        int i = 0, j = s.size()-1;
        int min = 0;
        bool check = false;
        while(j>i){
            char ch = s[i];
            while(j>i&&s[j]==ch){
                j--; check = true; min++;
            }
            if(check){
                while(j>=i&&s[i]==ch){
                    i++; min++;
                }
            }
            else
                break;
            check = false;
        }
        return s.size()-min;
    }
};