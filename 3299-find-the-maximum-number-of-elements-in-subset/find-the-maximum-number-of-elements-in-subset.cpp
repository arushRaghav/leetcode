class Solution {
private:
    static constexpr uint16_t MAXQ = 31622u;
    static uint8_t counts[MAXQ-1u];

public:
    static int maximumLength(vector<int>& nums) {
        const uint n = nums.size();
        unordered_set<uint> bigcounts;
        uint minv = MAXQ, maxv = 2, ones = 0;
        for (uint i = 0; i < n; i++) {
            const uint v = nums[i];
            if (v == 1u) ones++;
            else if (v <= MAXQ) {
                if (counts[v-2u] < 2u) counts[v-2u]++;
                minv = min(minv, v);
                maxv = max(maxv, v);
            } else {
                bigcounts.insert(v);
            }
        }
        uint maxc = ones ? max((ones - 1u) | 1u, 1u) : 1u;
        uint topc = 9;
        constexpr uint8_t topb[] = { 4, 14, 178 };
        uint8_t topp = 0;
        uint v;
        for (v = minv; v <= maxv && maxc <= topc; v++) {
            uint c = 0;
            uint64_t sq = v;
            for ( ; sq <= MAXQ; sq *= sq) {
                const uint d = counts[sq-2u];
                if (d) c++;
                if (d < 2u) break;
            }
            if (sq > MAXQ && bigcounts.contains(sq))
                c++;
            maxc = max(c * 2u, maxc + 1u) - 1u;
            if (topp < 3u && topb[topp] == v) {
                topc -= 2u;
                topp++;
            }
        }
        if (minv <= maxv)
            fill(counts + minv - 2u, counts + maxv - 1u, 0);
        return maxc;
    }
};

uint8_t Solution::counts[MAXQ-1u];