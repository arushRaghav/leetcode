class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> va(s.size() + 1, 0); //length of valid parentheses
        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')' && (i - va[i] - 1) >= 0 && s[i - va[i] - 1] == '(')
                va[i + 1] = va[i] + 2 + va[i - va[i] - 1];
            ans = max(ans, va[i + 1]);
        }
        return ans;
    }
};