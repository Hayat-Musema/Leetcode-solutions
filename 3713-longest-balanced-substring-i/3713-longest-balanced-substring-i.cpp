class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> cnt(26, 0);
            int distinct = 0;
            int maxFreq = 0;

            for (int j = i; j < n; ++j) {
                int c = s[j] - 'a';
                if (cnt[c] == 0) ++distinct;
                cnt[c]++;
                maxFreq = max(maxFreq, cnt[c]);

                // Check if all non‑zero counts are equal:
                // if maxFreq * distinct == substring length
                if (maxFreq * distinct == (j - i + 1)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};