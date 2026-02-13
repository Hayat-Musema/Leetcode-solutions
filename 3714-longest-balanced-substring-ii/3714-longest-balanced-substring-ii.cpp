class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        // Case 1: single character repeated
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                ans = max(ans, count);
                count = 1;
            }
        }
        ans = max(ans, count);

        // Case 2: 2 characters balanced
        ans = max(ans, solveTwo(s, 'a', 'b'));
        ans = max(ans, solveTwo(s, 'b', 'c'));
        ans = max(ans, solveTwo(s, 'a', 'c'));

        // Case 3: 3 characters balanced
        ans = max(ans, solveThree(s));

        return ans;
    }

private:
    int solveTwo(const string &s, char a, char b) {
        int n = s.size(), res = 0;
        int i = 0;
        while (i < n) {
            // skip chars not in {a, b}
            while (i < n && s[i] != a && s[i] != b) i++;
            if (i >= n) break;

            unordered_map<int, int> pos;
            pos[0] = i - 1;
            int diff = 0;
            while (i < n && (s[i] == a || s[i] == b)) {
                diff += (s[i] == a ? 1 : -1);
                if (pos.count(diff)) {
                    res = max(res, i - pos[diff]);
                } else {
                    pos[diff] = i;
                }
                i++;
            }
        }
        return res;
    }

    int solveThree(const string &s) {
        int n = s.size(), res = 0;
        unordered_map<long long, int> pos;

        // Map (cnt[a]-cnt[b], cnt[b]-cnt[c]) to index
        pos[(0LL << 32) | (0LL & 0xffffffff)] = -1;
        int ca = 0, cb = 0, cc = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') ca++;
            else if (s[i] == 'b') cb++;
            else cc++;

            int d1 = ca - cb;
            int d2 = cb - cc;
            long long key = (((long long)d1) << 32) ^ (unsigned long long)(d2 & 0xffffffff);
            if (pos.count(key)) {
                res = max(res, i - pos[key]);
            } else {
                pos[key] = i;
            }
        }
        return res;
    }
};