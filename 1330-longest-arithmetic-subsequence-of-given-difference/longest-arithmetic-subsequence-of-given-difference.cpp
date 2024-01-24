# define shift 20000
static auto _ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {

        int res {0};
        for (const int& num: arr) {
            st[num + shift] = st[num - difference + shift] + 1;
            res = max(res, st[num + shift]);
        }
        return res;
    }
private:
    int st[2 * shift + 1] {0};
};